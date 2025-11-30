/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 18:43:38 by dinguyen          #+#    #+#             */
/*   Updated: 2025/11/30 08:05:35 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("unknown shrub form", 145, 137),
	_target("unknown target") {
	std::cout<<"ShrubberyCreationForm default constructor called"<<std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) :
	AForm("ShrubberyCreationForm", 145, 137), _target(target) {
		std::cout<<"ShrubberyCreationForm constructor called with parameter : "<<std::endl;
		std::cout<<"Target : "<<_target<<std::endl;};

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) :
	AForm(other), _target(other._target) {
	std::cout<<"ShrubberyCreationForm copy constructor called"<<std::endl;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
	std::cout<<"ShrubberyCreationForm copy assignment operator called"<<std::endl;
	if (this != &other) {
		AForm::operator=(other);
		_target = other._target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout<<"ShrubberyCreationForm destructor called"<<std::endl;
}

const char*	ShrubberyCreationForm::OpenFileE::what() const throw() {
	const char*	result = "Error opening file";
	return (result);
}

void	ShrubberyCreationForm::execute(const Bureaucrat &b) const {
	_checkExecution(b);
	std::ofstream	outfile((_target + "_shrubbery").c_str());
	if (!outfile)
		throw ShrubberyCreationForm::OpenFileE();
	outfile<<"     ^     "<<std::endl;
	outfile<<"    ^^^    "<<std::endl;
	outfile<<"   ^^^^^   "<<std::endl;
	outfile<<"  ^^^^^^^  "<<std::endl;
	outfile<<" ^^^^^^^^^ "<<std::endl;
	outfile<<"     +     "<<std::endl;
	outfile.close();
}
