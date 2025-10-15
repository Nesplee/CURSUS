/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 13:53:55 by dinguyen          #+#    #+#             */
/*   Updated: 2025/09/04 13:56:15 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
	_type = "WrongCat";
	std::cout<<"WrongCat constructor called"<<std::endl;
}

WrongCat::~WrongCat() {
	std::cout<<"WrongCat destructor called"<<std::endl;
}

void	WrongCat::makeSound() const {
	std::cout<<"* Wrong Meow! Wrong Meow! *"<<std::endl;
}
