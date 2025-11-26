/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:06:23 by dinguyen          #+#    #+#             */
/*   Updated: 2025/11/25 11:13:29 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
	_type = "WrongCat";
	std::cout<<"WrongCat default constructor called"<<std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) {
	std::cout<<"WrongCat copy constructor called"<<std::endl;
}

WrongCat&	WrongCat::operator=(const WrongCat &other) {
	std::cout<<"WrongCat copy assignment operator called"<<std::endl;
	if (this != &other) {
		WrongAnimal::operator=(other);
	}
	return (*this);
}

WrongCat::~WrongCat() {
	std::cout<<"WrongCat destructor called"<<std::endl;
}

void	WrongCat::makeSound() const {
	std::cout<<" mEoW bRokEn"<<std::endl;
}
