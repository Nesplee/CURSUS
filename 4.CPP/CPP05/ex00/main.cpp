/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 08:12:31 by dinguyen          #+#    #+#             */
/*   Updated: 2025/11/27 14:21:49 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main() {
	try {
		Bureaucrat b1("Boyzer", 42);
		std::cout<<b1<<std::endl;
	} catch (std::exception &e) {
		std::cout<<"Error creation b1: "<<e.what()<<std::endl;
	}
	try {
		Bureaucrat b2("Boyzer2", 0);
		std::cout<<b2<<std::endl;
	} catch (std::exception &e) {
		std::cout<<"Error creation b2: "<<e.what()<<std::endl;
	}
	try {
		Bureaucrat b3("Boyzer3", 151);
		std::cout<<b3<<std::endl;
	} catch (std::exception &e) {
		std::cout<<"Error creation b3: "<<e.what()<<std::endl;
	}
	try {
		Bureaucrat b4("Boyzer4", 2);
		std::cout<<b4<<std::endl;
		b4.incrementGrade();
		std::cout<<b4<<std::endl;
		b4.incrementGrade();
	} catch (std::exception &e) {
		std::cout<<"Error increment b4 : "<<e.what()<<std::endl;
	}
	try {
		Bureaucrat b5("Boyzer5", 149);
		std::cout<<b5<<std::endl;
		b5.decrementGrade();
		std::cout<<b5<<std::endl;
		b5.decrementGrade();
	} catch (std::exception &e) {
		std::cout<<"Error decrement b5 : "<<e.what()<<std::endl;
	}
	try {
		Bureaucrat b6("Boyzer6", 10);
		std::cout<<b6<<std::endl;
		Bureaucrat b7(b6);
		std::cout<<b7<<std::endl;
		Bureaucrat b8("Boyzer8", 100);
		b8 = b6;
		std::cout<<b8<<std::endl;
	} catch (std::exception &e) {
		std::cout<<"Error copy/affectation : "<<e.what()<<std::endl;
	}
	Bureaucrat b9;
	std::cout << b9 << std::endl;
	return (0);
}
