/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 08:12:31 by dinguyen          #+#    #+#             */
/*   Updated: 2025/11/30 10:15:05 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>

int	main() {
	std::srand(std::time(0));
	try {
		Bureaucrat b("ErrorGuy", 0);
	} catch (std::exception &e) {
		std::cout<<"Error Bureaucrat creation : "<<e.what()<<std::endl;
	}
	try {
		Bureaucrat b("ErrorGuy", 151);
	} catch (std::exception &e) {
		std::cout << "Error Bureaucrat creation : " << e.what() << std::endl;
	}
	try {
		ShrubberyCreationForm	f("garden");
		Bureaucrat				b("lowguy", 150);
		b.signAForm(f);
		b.executeAForm(f);
	} catch (std::exception &e) {
		std::cout<<"Error Shrubbery test : "<<e.what()<<std::endl;
	}
	try {
		ShrubberyCreationForm	f("home");
		Bureaucrat				b("Boss", 1);
		b.signAForm(f);
		b.executeAForm(f);
	} catch (std::exception &e) {
		std::cout<<"Error Shrubbery test : "<<e.what()<<std::endl;
	}
	try {
		ShrubberyCreationForm	f("home");
		Bureaucrat				b("Boss", 1);
		b.executeAForm(f);
	} catch (std::exception &e) {
		std::cout<<"Error Shrubbery test : "<<e.what()<<std::endl;
	}
	try {
		RobotomyRequestForm		f("You");
		Bureaucrat				b("lowguy", 150);
		b.signAForm(f);
		b.executeAForm(f);
	} catch (std::exception &e) {
		std::cout<<"Error Robotomy test : "<<e.what()<<std::endl;
	}
	try {
		RobotomyRequestForm		f("You");
		Bureaucrat				b("Boss", 1);
		b.signAForm(f);
		b.executeAForm(f);
	} catch (std::exception &e) {
		std::cout<<"Error Robotomy test : "<<e.what()<<std::endl;
	}
	try {
		RobotomyRequestForm		f("You");
		Bureaucrat				b("Boss", 1);
		b.executeAForm(f);
	} catch (std::exception &e) {
		std::cout<<"Error Robotomy test : "<<e.what()<<std::endl;
	}
	try {
		PresidentialPardonForm	f("You");
		Bureaucrat				b("lowguy", 150);
		b.signAForm(f);
		b.executeAForm(f);
	} catch (std::exception &e) {
		std::cout<<"Error Presidential test : "<<e.what()<<std::endl;
	}
	try {
		PresidentialPardonForm	f("You");
		Bureaucrat				b("Boss", 1);
		b.signAForm(f);
		b.executeAForm(f);
	} catch (std::exception &e) {
		std::cout<<"Error Presidential test : "<<e.what()<<std::endl;
	}
	try {
		PresidentialPardonForm	f("You");
		Bureaucrat				b("Boss", 1);
		b.executeAForm(f);
	} catch (std::exception &e) {
		std::cout<<"Error Presidential test : "<<e.what()<<std::endl;
	}
	return(0);
}
