/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:14:17 by dinguyen          #+#    #+#             */
/*   Updated: 2025/10/13 15:25:23 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() : _firstName(""), _lastName(""), _nickName(""),
		_phoneNumber(""), _darkestSecret("") {
	std::cout<<"Contact default constructor called"<<std::endl;
}

Contact::~Contact() {
	std::cout<<"Contact destructor called"<<std::endl;
}

/*
===============================================================================
						PUBLICS METHODS
===============================================================================
*/

std::string	Contact::getFirstName(void) const { return (_firstName); }
std::string	Contact::getLastName(void) const { return (_lastName); }
std::string	Contact::getNickName(void) const { return (_nickName); }
std::string	Contact::getPhoneNumber(void) const { return (_phoneNumber); }
std::string	Contact::getDarkestSecret(void) const { return (_darkestSecret); }

void	Contact::displayContact(void) const {
	std::cout<<"First name        : "<<_firstName<<std::endl;
	std::cout<<"Last name         : "<<_lastName<<std::endl;
	std::cout<<"Nickname          : "<<_nickName<<std::endl;
	std::cout<<"Phone number      : "<<_phoneNumber<<std::endl;
	std::cout<<"Darkest secret    : "<<_darkestSecret<<std::endl;
}

void	Contact::recordContact(void) {
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

/*
===============================================================================
						PRIVATES METHODS
===============================================================================
*/

void	Contact::_setFirstName(const std::string &name) { _firstName = name; }
void	Contact::_setLastName(const std::string &name) { _lastName = name; }
void	Contact::_setNickName(const std::string &name) { _nickName = name; }
void	Contact::_setPhoneNumber(const std::string &number) { _phoneNumber = number; }
void	Contact::_setDarkestSecret(const std::string &secret) { _darkestSecret = secret; }

bool	Contact::_isValidPhoneNumber(const std::string &number) const {
	if (number.empty()) return (false);
	std::size_t 		start = 0;
	const std::size_t	len = number.length();
	if (number[0] == '+') {
		start = 1;
		if (len == 1)
			return (false);
	}
	for (std::size_t i = start; i < len; i++) {
		if (number[i] < '0' || number[i] > '9')
			return (false);
	}
	return (true);
}

std::string	Contact::_getInput(const std::string &prompt) const {
	std::string	input;
	std::cout<<prompt;
	std::getline(std::cin, input);
	while (input.empty() || input.length() > 15) {
		if (input.empty())
			std::cout<<"Please enter a valid answer"<<std::endl;
		else
			std::cout<<"Entry too long, 15 characters maximum"<<std::endl;
		std::cout<<prompt;
		std::getline(std::cin, input);
	}
	return (input);
}

std::string	Contact::_getPhoneNumber(const std::string &prompt) const {
	std::string	number;
	std::cout<<prompt;
	std::getline(std::cin, number);
	while (number.empty() || number.length() > 15 || !_isValidPhoneNumber(number)) {
		if (number.empty()) { std::cout<<"Please enter a valid number"<<std::endl; }
		else if (number.length() > 15) { std::cout<<"Number too long, 15 characters maximum"<<std::endl; }
		else { std::cout<<"Only '+' and digits allowed for number"<<std::endl; }
		std::cout<<prompt;
		std::getline(std::cin, number);
	}
	return (number);
}
