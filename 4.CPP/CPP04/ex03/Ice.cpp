/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 11:24:12 by dinguyen          #+#    #+#             */
/*   Updated: 2025/11/26 14:52:09 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice() : AMateria("ice") {
	_type = "ice";
	std::cout<<"Ice default constructor called"<<std::endl;
}

Ice::Ice(const Ice &other) : AMateria(other) {
	_type = other._type;
	std::cout<<"Ice copy constructor called"<<std::endl;
}

Ice&	Ice::operator=(const Ice &other) {
	std::cout<<"Ice copy assignment operator called"<<std::endl;
	if (this != &other ) {
		AMateria::operator=(other);
	}
	return (*this);
}

Ice::~Ice() {
	std::cout<<"Ice destructor called"<<std::endl;
}

void	Ice::use(ICharacter &target) {
	std::cout<<"* shoots an ice bolt at "<<target.getName()<<" *"<<std::endl;
}

AMateria*	Ice::clone() const {
	AMateria	*clone = new Ice();
	return (clone);
}
