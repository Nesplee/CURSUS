/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 13:14:12 by dinguyen          #+#    #+#             */
/*   Updated: 2025/09/04 13:21:59 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal() {
	_type = "Dog";
	std::cout<<"Dog constructor called"<<std::endl;
}

Dog::~Dog() {
	std::cout<<"Dog destructor called"<<std::endl;
}

void	Dog::makeSound() const {
	std::cout<<" Woof! Woof!"<<std::endl;
}
