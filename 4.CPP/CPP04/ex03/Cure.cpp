/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 11:49:06 by dinguyen          #+#    #+#             */
/*   Updated: 2025/11/26 14:52:10 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure() : AMateria("cure") {
	_type = "cure";
	std::cout<<"Cure default constructor called"<<std::endl;
}

Cure::Cure(const Cure &other) : AMateria(other) {
	_type = other._type;
	std::cout<<"Cure copy constructor called"<<std::endl;
}

Cure&	Cure::operator=(const Cure &other) {
	std::cout<<"Cure copy assignment operator called"<<std::endl;
	if (this != &other) {
		AMateria::operator=(other);
	}
	return (*this);
}

Cure::~Cure() {
	std::cout<<"Cure destructor called"<<std::endl;
}

AMateria*	Cure::clone() const {
	AMateria*	clone = new Cure();
	return (clone);
}

void	Cure::use(ICharacter &target) {
	std::cout<<"* heals "<<target.getName()<<"'s wounds *"<<std::endl;
}
