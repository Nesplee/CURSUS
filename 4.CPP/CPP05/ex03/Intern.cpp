/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 09:54:02 by dinguyen          #+#    #+#             */
/*   Updated: 2025/11/30 11:21:11 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"


AForm*	Intern::createShrubbery(const std::string &target) {
	AForm*	f = new ShrubberyCreationForm(target);
	return (f);
}

AForm*	Intern::createRobotomy(const std::string &target) {
	AForm*	f = new RobotomyRequestForm(target);
	return (f);
}

AForm*	Intern::createPresidential(const std::string &target) {
	AForm*	f = new PresidentialPardonForm(target);
	return (f);
}

Intern::Intern() {
	std::cout<<"Intern default constructor called"<<std::endl;
}

Intern::Intern(const Intern &other) {
	(void)other;
	std::cout<<"Intern copy constructor called"<<std::endl;
}

Intern&	Intern::operator=(const Intern &other) {
	(void)other;
	std::cout<<"Intern copy assignment operator called"<<std::endl;
	return (*this);
}

Intern::~Intern() {
	std::cout<<"Intern destructor called"<<std::endl;
}

const char*	Intern::InvalidFormNameE::what() const throw() {
	const char*	result = "Invalid Form Name";
	return (result);
}

AForm*	Intern::makeForm(const std::string &formName, const std::string &target) {
	std::string	goodForms[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	AForm*		(*functions[3])(const std::string&) = {
		&Intern::createShrubbery,
		&Intern::createRobotomy,
		&Intern::createPresidential
	};
	for (int i = 0; i < 3; i++) {
		if (formName == goodForms[i]) {
			std::cout << "Intern creates " << goodForms[i] << std::endl;
			return functions[i](target);
		}
	}
	throw InvalidFormNameE();
	return (NULL);
}
