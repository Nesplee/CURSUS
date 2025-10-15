/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 08:57:19 by dinguyen          #+#    #+#             */
/*   Updated: 2025/10/14 11:07:02 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main() {
	std::string		string = "HI THIS IS BRAIN";
	std::string*	stringPTR = &string;
	std::string&	stringREF = string;
	std::cout<<"================================================="<<std::endl;
	std::cout<<"                    ADDRESSES"<<std::endl;
	std::cout<<"================================================="<<std::endl;
	std::cout<<"Address of the string variable: "<<&string<<std::endl;
	std::cout<<"Address held by stringPTR: "<<stringPTR<<std::endl;
	std::cout<<"Address held by stringREF: "<<&stringREF<<std::endl;
	std::cout<<"================================================="<<std::endl;
	std::cout<<"                    VALUES"<<std::endl;
	std::cout<<"================================================="<<std::endl;
	std::cout<<"Value of the string variable: "<<string<<std::endl;
	std::cout<<"Value pointed to by stringPTR: "<<*stringPTR<<std::endl;
	std::cout<<"Value pointed to by stringREF: "<<stringREF<<std::endl;
	return (0);
}
