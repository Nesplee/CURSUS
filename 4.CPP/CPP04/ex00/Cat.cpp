/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 09:57:51 by dinguyen          #+#    #+#             */
/*   Updated: 2025/11/25 10:25:05 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal() {
	_type = "Cat";
	std::cout<<"Cat default constructor called"<<std::endl;
}

Cat::Cat(const Cat &other) : Animal(other) {
	std::cout<<"Cat copy constructor called"<<std::endl;
}

Cat&	Cat::operator=(const Cat &other) {
	std::cout<<"Cat copy assignment operator called"<<std::endl;
	if (this != &other) {
		Animal::operator=(other);
	}
	return (*this);
}

Cat::~Cat() {
	std::cout<<"Cat destructor called"<<std::endl;
}

void	Cat::makeSound() const {
	std::cout<<" MEEEEEEOW! MMMEEEEOOWWWWW"<<std::endl;
}

