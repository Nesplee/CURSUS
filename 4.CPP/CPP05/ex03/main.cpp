/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 08:12:31 by dinguyen          #+#    #+#             */
/*   Updated: 2025/11/30 10:43:10 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>
#include "Intern.hpp"

int	main() {
	std::srand(std::time(0));
	Intern	intern;
	Bureaucrat	boss("Boss", 1);
	Bureaucrat	bouz("Bouz", 150);

	try {
		AForm*	shrub = intern.makeForm("ShrubberyCreationForm", "park");
		boss.signAForm(*shrub);
		boss.executeAForm(*shrub);
		delete shrub;
	} catch (std::exception &e) {
		std::cout<<"Intern shrubbery creation error: "<<e.what()<<std::endl;
	}
	try {
		AForm*	robot = intern.makeForm("RobotomyRequestForm", "you");
		boss.signAForm(*robot);
		boss.executeAForm(*robot);
		delete robot;
	} catch (std::exception &e) {
		std::cout<<"Intern robotomy creation error: "<<e.what()<<std::endl;
	}
	try {
		AForm*	prez = intern.makeForm("PresidentialPardonForm", "me");
		boss.signAForm(*prez);
		boss.executeAForm(*prez);
		delete prez;
	} catch (std::exception &e) {
		std::cout<<"Intern presidential creation error: "<<e.what()<<std::endl;
	}
	try {
		AForm*	unknown = intern.makeForm("BRINGACOFFEE", "ME");
		delete unknown;
	} catch (std::exception &e) {
		std::cout<<"Intern unknown form error : "<<e.what()<<std::endl;
	}
	return (0);
}
