/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 10:45:52 by dinguyen          #+#    #+#             */
/*   Updated: 2025/11/28 15:49:46 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("unknown form"), _isSigned(false), _gradeToSign(150), _gradeToExec(150) {
	std::cout<<"Form default constructor called"<<std::endl;
}

Form::Form(const std::string &name, const int signG, const int execG) :
	_name(name), _isSigned(false), _gradeToSign(signG), _gradeToExec(execG) {
	if (signG < 1 || execG < 1)
		throw GradeTooHighE();
	else if (signG > 150 || execG > 150)
		throw GradeTooLowE();
	std::cout<<"Form constructor with parameters called"<<std::endl;
	std::cout<<"Name : "<<_name<<std::endl;
	std::cout<<"Form signed : "<<_isSigned<<std::endl;
	std::cout<<"Grade required to sign : "<<_gradeToSign<<std::endl;
	std::cout<<"Grade required to execute : "<<_gradeToExec<<std::endl;
}

Form::Form(const Form &other) : _name(other._name), _isSigned(other._isSigned),
	_gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec) {
	std::cout<<"Form copy constructor called"<<std::endl;
}

Form&	Form::operator=(const Form& other) {
	std::cout<<"Form copy assignment operator called"<<std::endl;
	if (this != &other ) {
		_isSigned = other._isSigned;
	}
	return (*this);
}

Form::~Form() {
	std::cout<<"Form destructor called"<<std::endl;
}

bool	Form::getIsSigned() const { return (_isSigned); }
int	Form::getGradeToSign() const { return (_gradeToSign); }
int	Form::getGradeToExec() const { return (_gradeToExec); }
const std::string&	Form::getName() const { return (_name); }

void	Form::beSigned(const Bureaucrat &b) {
	if (_isSigned) {
		throw std::runtime_error("Form already signed!");
	}
	if (b.getGrade() <= _gradeToSign) {
		_isSigned = true;
	} else {
		throw Form::GradeTooLowE();
	}
}

const char*	Form::GradeTooHighE::what() const throw() {
	const char*	result = "Form Grade too High!";
	return (result);
}

const char*	Form::GradeTooLowE::what() const throw() {
	const char*	result = "Form Grade too Low!";
	return (result);
}

std::ostream&	operator<<(std::ostream& os, const
	Form &f) {
	os<<"Name : "<<f.getName();
	os<<"/ is signed : "<<f.getIsSigned();
	os<<"/ Grade to sign : "<<f.getGradeToSign();
	os<<"/ Grade to exec : "<<f.getGradeToExec()<<std::endl;
	return (os);
}

