/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 08:12:31 by dinguyen          #+#    #+#             */
/*   Updated: 2025/11/28 15:45:57 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main() {
	try {
		Bureaucrat b("ErrorGuy", 0);
	} catch (std::exception &e) {
		std::cout << "Error Bureaucrat creation : " << e.what() << std::endl;
	}
	try {
		Bureaucrat b("ErrorGuy", 151);
	} catch (std::exception &e) {
		std::cout << "Error Bureaucrat creation : " << e.what() << std::endl;
	}
	try {
		Form f("FormError", 0, 10);
	} catch (std::exception &e) {
		std::cout << "Error Form creation : " << e.what() << std::endl;
	}
	try {
		Form f("FormError", 10, 151);
	} catch (std::exception &e) {
		std::cout << "Error Form creation : " << e.what() << std::endl;
	}
	try {
		Bureaucrat b1("LowGuy", 150);
		Form f1("Form1", 120, 120);
		b1.signForm(f1);
		std::cout << f1 << std::endl;
	} catch (std::exception &e) {
		std::cout << "Error b1 : " << e.what() << std::endl;
	}
	try {
		Bureaucrat b2("HighGuy", 5);
		Form f2("Form2", 10, 5);
		b2.signForm(f2);
		std::cout << f2 << std::endl;
	} catch (std::exception &e) {
		std::cout << "Error b2 : " << e.what() << std::endl;
	}
	try {
		Bureaucrat b3("MiddleGuy", 50);
		Form f3("Form3", 50, 50);
		std::cout << f3 << std::endl;
		b3.signForm(f3);
		std::cout << f3 << std::endl;
	} catch (std::exception &e) {
		std::cout << "Error b3 : " << e.what() << std::endl;
	}
	try {
		Bureaucrat b4("Signer", 1);
		Form f4("Form4", 100, 100);
		b4.signForm(f4);
		b4.signForm(f4);
		std::cout << f4 << std::endl;
	} catch (std::exception &e) {
		std::cout << "Error b4 : " << e.what() << std::endl;
	}
	return 0;
}
