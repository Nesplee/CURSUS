/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 07:51:12 by dinguyen          #+#    #+#             */
/*   Updated: 2025/11/30 08:06:28 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("unknown pres form", 25, 5),
	_target("unknown target") {
		std::cout<<"PresidentialPardonForm default constructor called"<<std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) :
	AForm("PresidentialPardonForm", 25, 5), _target(target) {
		std::cout<<"PresidentialPardonForm constructor called with parameter : "<<std::endl;
		std::cout<<"Target : "<<_target<<std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) :
	AForm(other), _target(other._target) {
		std::cout<<"PresidentialPardonForm copy constructor called"<<std::endl;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
	std::cout<<"PresidentialPardonForm copy assignment operator called"<<std::endl;
	if (this != &other ) {
		AForm::operator=(other);
		_target = other._target;
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout<<"PresidentialPardonForm destructor called"<<std::endl;
}

void	PresidentialPardonForm::execute(const Bureaucrat &b) const {
	_checkExecution(b);
	std::cout<<_target<<" has been pardoned by Zaphod Beeblebrox."<<std::endl;
}
