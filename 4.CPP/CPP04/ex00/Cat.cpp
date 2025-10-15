/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 13:22:24 by dinguyen          #+#    #+#             */
/*   Updated: 2025/09/04 13:26:52 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal() {
	_type = "Cat";
	std::cout<<"Cat constructor called"<<std::endl;
}

Cat::~Cat() {
	std::cout<<"Cat destructor called"<<std::endl;
}

void	Cat::makeSound() const {
	std::cout<<" Meow! Meow!"<<std::endl;
}
