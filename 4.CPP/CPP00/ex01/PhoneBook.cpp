/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:42:52 by dinguyen          #+#    #+#             */
/*   Updated: 2025/10/13 17:16:57 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook() : _currentSize(0), _nextIndex(0) {
	std::cout<<"PhoneBook default constructor called"<<std::endl;
}

PhoneBook::~PhoneBook() {
	std::cout<<"PhoneBook destructor called"<<std::endl;
}

std::string	PhoneBook::_formatColumn(const std::string &text) const {
	std::string	result;

	if (text.length() <= 10) {
		result = text;
		while (result.length() < 10) { result = " " + result;}
	}
	else
		result = text.substr(0, 9) + '.';
	return (result);
}

void	PhoneBook::_displayHeader(void) const {
	std::cout<<"|----------|----------|----------|----------|"<<std::endl;
	std::cout<<"|     Index|First Name| Last Name|  Nickname|"<<std::endl;
	std::cout<<"|----------|----------|----------|----------|"<<std::endl;
}

void	PhoneBook::_displayTable(void) const {
	for (int i = 0; i < _currentSize; i++) {
		std::cout<<"|         "<<i<<"|";
		std::cout<<_formatColumn(_contacts[i].getFirstName())<<"|";
		std::cout<<_formatColumn(_contacts[i].getLastName())<<"|";
		std::cout<<_formatColumn(_contacts[i].getNickName())<<"|";
		std::cout<<std::endl;
	}
}

void	PhoneBook::_displayContactList(void) const {
	_displayHeader();
	_displayTable();
}

void	PhoneBook::addContact(void) {
	_contacts[_nextIndex].recordContact();
	if (_currentSize < 8)
		_currentSize++;
	if (_nextIndex == 7)
		_nextIndex = 0;
	else
		_nextIndex++;
}

void	PhoneBook::searchContact(void) const {
	int	index;
	if (_currentSize == 0) {
		std::cout<<"No contacts to display!"<<std::endl;
		return ;
	}
	_displayContactList();
	std::cout<<"Enter the index of the contact you wanna check"<<std::endl;
	std::cin>>index;
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cout<<"Invalid input! Please enter a valid number"<<std::endl;
		return ;
	}
	std::cin.ignore();
	if (index >= 0 && index < _currentSize)
		_contacts[index].displayContact();
	else
		std::cout<<"Index not found or invalid"<<std::endl;
}
