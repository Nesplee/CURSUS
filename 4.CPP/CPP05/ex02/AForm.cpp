/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 10:45:52 by dinguyen          #+#    #+#             */
/*   Updated: 2025/11/28 16:12:00 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("unknown AForm"), _isSigned(false), _gradeToSign(150), _gradeToExec(150) {
	std::cout<<"AForm default constructor called"<<std::endl;
}

AForm::AForm(const std::string &name, const int signG, const int execG) :
	_name(name), _isSigned(false), _gradeToSign(signG), _gradeToExec(execG) {
	if (signG < 1 || execG < 1)
		throw GradeTooHighE();
	else if (signG > 150 || execG > 150)
		throw GradeTooLowE();
	std::cout<<"AForm constructor with parameters called"<<std::endl;
	std::cout<<"Name : "<<_name<<std::endl;
	std::cout<<"AForm signed : "<<_isSigned<<std::endl;
	std::cout<<"Grade required to sign : "<<_gradeToSign<<std::endl;
	std::cout<<"Grade required to execute : "<<_gradeToExec<<std::endl;
}

AForm::AForm(const AForm &other) : _name(other._name), _isSigned(other._isSigned),
	_gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec) {
	std::cout<<"AForm copy constructor called"<<std::endl;
}

AForm&	AForm::operator=(const AForm& other) {
	std::cout<<"AForm copy assignment operator called"<<std::endl;
	if (this != &other ) {
		_isSigned = other._isSigned;
	}
	return (*this);
}

AForm::~AForm() {
	std::cout<<"AForm destructor called"<<std::endl;
}

bool	AForm::getIsSigned() const { return (_isSigned); }
int	AForm::getGradeToSign() const { return (_gradeToSign); }
int	AForm::getGradeToExec() const { return (_gradeToExec); }
const std::string&	AForm::getName() const { return (_name); }

void	AForm::beSigned(const Bureaucrat &b) {
	if (_isSigned) {
		throw std::runtime_error("AForm already signed!");
	}
	if (b.getGrade() <= _gradeToSign) {
		_isSigned = true;
	} else {
		throw AForm::GradeTooLowE();
	}
}

const char*	AForm::GradeTooHighE::what() const throw() {
	const char*	result = "Grade too High!";
	return (result);
}

const char*	AForm::GradeTooLowE::what() const throw() {
	const char*	result = "Grade too Low!";
	return (result);
}

const char*	AForm::NotSignedE::what() const throw() {
	const char*	result = "Form not signed!";
	return (result);
}

void	AForm::_checkExecution(const Bureaucrat &b) const {
	if (!getIsSigned())
		throw NotSignedE();
	if (b.getGrade() > getGradeToExec())
		throw GradeTooLowE();
}

std::ostream&	operator<<(std::ostream& os, const
	AForm &f) {
	os<<"Name : "<<f.getName();
	os<<"/ is signed : "<<f.getIsSigned();
	os<<"/ Grade to sign : "<<f.getGradeToSign();
	os<<"/ Grade to exec : "<<f.getGradeToExec()<<std::endl;
	return (os);
}

