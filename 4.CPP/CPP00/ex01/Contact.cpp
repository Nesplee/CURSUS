/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 09:37:11 by dinguyen          #+#    #+#             */
/*   Updated: 2025/10/13 11:49:45 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

//	CONSTRUCTOR AND DESTRUCTOR
Contact::Contact() : _firstName(""), _lastName(""), _nickName(""),
	_phoneNumber(""), _darkestSecret("") {
		std::cout<<"Contact constructor called"<<std::endl;
}

Contact::~Contact() {
	std::cout<<"Contact destructor called"<<std::endl;
}

/* ========================================================================= */
/*								PRIVATES METHODS							 */
/* ========================================================================= */

//	INPUT
std::string	Contact::_getInput(const std::string &prompt) const {
	std::string	input;
	std::cout<<prompt;
	std::getline(std::cin, input);
	while (input.empty() || input.length() > 30)
	{
		if (input.empty())
			std::cout<<"Please enter at least one character.."<<std::endl;
		else
			std::cout<<"Entry too long. 30 characters maximum."<<std::endl;
		std::cout<<prompt;
		std::getline(std::cin, input);
	}
	return (input);
}

bool	Contact::_isValidNumber(const std::string &number) const {
	int	i = 0;
	if (number[i] == '+')
		i = 1;
	while (i < (int)number.length()) {
		if (number[i] < '0' || number[i] > '9')
			return (false);
		i++;
	}
	return (true);
}

std::string Contact::_getPhoneNumber(const std::string &prompt) const {
	std::string	input;
	std::cout<<prompt;
	std::getline(std::cin, input);
	while (input.empty() || input.length() > 30 || !_isValidNumber(input))
	{
		if (input.empty())
			std::cout<<"Please enter a valid phone number."<<std::endl;
		else if (input.length() > 12)
			std::cout<<"Number too long. Enter a valid phone number please"<<std::endl;
		else
			std::cout<<"Only digits and '+' allowed"<<std::endl;
		std::cout<<prompt;
		std::getline(std::cin, input);
	}
	return (input);
}

//	SETTERS
void	Contact::_setFirstName(const std::string &name) { _firstName = name; }
void	Contact::_setLastName(const std::string &name) { _lastName = name; }
void	Contact::_setNickName(const std::string &name) { _nickName = name; }
void	Contact::_setPhoneNumber(const std::string &number) { _phoneNumber = number; }
void	Contact::_setDarkestSecret(const std::string &secret) { _darkestSecret = secret; }

/* ========================================================================= */
/*								PUBLICS METHODS								 */
/* ========================================================================= */

std::string	Contact::getFirstName() const { return (_firstName); }
std::string	Contact::getLastName() const { return (_lastName); }
std::string	Contact::getNickName() const { return (_nickName); }
std::string	Contact::getPhoneNumber() const { return (_phoneNumber); }
std::string	Contact::getDarkestSecret() const{ return (_darkestSecret); }

void	Contact::displayContact() const {
	std::cout<<"First Name        : "<<_firstName<<std::endl;
	std::cout<<"Last Name         : "<<_lastName<<std::endl;
	std::cout<<"Nickname          : "<<_nickName<<std::endl;
	std::cout<<"Phone Number      : "<<_phoneNumber<<std::endl;
	std::cout<<"Darkest Secret    : "<<_darkestSecret<<std::endl;
}

void	Contact::recordContact() {
	std::string	input;

	input = _getInput("Please enter your first name: ");
	_setFirstName(input);
	input = _getInput("Please enter your last name: ");
	_setLastName(input);
	input = _getInput("Please enter your nickname: ");
	_setNickName(input);
	input = _getPhoneNumber("Please enter your phone number: ");
	_setPhoneNumber(input);
	input = _getInput("Please enter your darkest secret: ");
	_setDarkestSecret(input);
}
