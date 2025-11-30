/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 07:07:16 by dinguyen          #+#    #+#             */
/*   Updated: 2025/11/30 10:15:00 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("unknown robot form", 72, 45),
	_target("unknown target") {
		std::cout<<"RobotomyRequestForm default constructor called"<<std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", 72, 45),
	_target(target) {
		std::cout<<"RobotomyRequestForm constructor called with parameter : "<<std::endl;
		std::cout<<"Target : "<<_target<<std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) :
	AForm(other), _target(other._target) {
		std::cout<<"RobotomyRequestForm copy constructor called"<<std::endl;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
	if (this != &other) {
		AForm::operator=(other);
		_target = other._target;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout<<"RobotomyRequestForm destructor called"<<std::endl;
}

void	RobotomyRequestForm::execute(const Bureaucrat &b) const {
	_checkExecution(b);
	std::cout<<" * DRILLING NOISES * "<<std::endl;
	if (std::rand() % 2 == 0)
		std::cout<<_target<<" has been robotomized successfully!"<<std::endl;
	else
		std::cout<<_target<<" : robotomy failed!"<<std::endl;
}
