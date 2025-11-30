/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 11:57:56 by dinguyen          #+#    #+#             */
/*   Updated: 2025/11/30 09:53:36 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Unknown Bureaucrat"), _grade(150) {
	std::cout<<"Bureaucrat default constructor called"<<std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name) {
	if (grade < 1)
		throw GradeTooHighE();
	else if (grade > 150)
		throw GradeTooLowE();
	_grade = grade;
	std::cout<<"Bureaucrat constructor with parameter :"<<std::endl;
	std::cout<<"Name : "<<_name<<std::endl;
	std::cout<<"Grade : "<<_grade<<std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade) {
	std::cout<<"Bureaucrat copy constructor called"<<std::endl;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat &other) {
	std::cout<<"Bureaucrat copy assignment operator called"<<std::endl;
	if (this != &other ) {
		_grade = other._grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat() {
	std::cout<<"Bureaucrat destructor called"<<std::endl;
}

const std::string&	Bureaucrat::getName() const { return (_name); }
int					Bureaucrat::getGrade() const { return (_grade); }

void				Bureaucrat::incrementGrade() {
	if (_grade <= 1)
		throw GradeTooHighE();
	_grade--;
}

void				Bureaucrat::decrementGrade() {
	if (_grade >= 150)
		throw GradeTooLowE();
	_grade++;
}

const char*	Bureaucrat::GradeTooHighE::what() const throw() {
	const char*	result = "Grade too High!";
	return (result);
}

const char*	Bureaucrat::GradeTooLowE::what() const throw() {
	const char*	result = "Grade too Low!";
	return (result);
}

void	Bureaucrat::signAForm(AForm &f) {
	try {
		f.beSigned(*this);
		std::cout<<this->getName()<<" signed "<<f.getName()<<std::endl;
	} catch (std::exception &e) {
		std::cout<<this->getName()<<" couldn't sign "<<f.getName()<<" because "<<e.what()<<std::endl;
	}
}

void	Bureaucrat::executeAForm(const AForm &f) const {
	try {
		f.execute(*this);
		std::cout<<this->getName()<<" executed "<<f.getName()<<std::endl;
	} catch (std::exception &e) {
		std::cout<<this->getName()<<" couldn't execute "<<f.getName()<<" because "<<e.what()<<std::endl;
	}
}

std::ostream& operator<<(std::ostream &os, const Bureaucrat &b) {
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return (os);
}

