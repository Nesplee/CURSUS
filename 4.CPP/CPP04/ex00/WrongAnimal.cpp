/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 13:31:36 by dinguyen          #+#    #+#             */
/*   Updated: 2025/09/04 13:47:13 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	std::cout<<"WrongAnimal constructor called"<<std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout<<"WrongAnimal destructor called"<<std::endl;
}

void	WrongAnimal::makeSound() const {
	std::cout<<"* Wrong sound wrong of wrong animal wrong , it's wrong*"<<std::endl;
}

std::string	WrongAnimal::getType() const { return (_type); }
