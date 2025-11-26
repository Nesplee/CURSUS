/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 19:49:37 by dinguyen          #+#    #+#             */
/*   Updated: 2025/11/26 13:02:02 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(const std::string &type) : _type(type) {
	std::cout<<"AMateria constructor called with type : "<<_type<<" called"<<std::endl;
}

AMateria::AMateria(const AMateria &other) : _type(other._type) {
	std::cout<<"AMateria copy constructor called"<<std::endl;
}

AMateria&	AMateria::operator=(const AMateria &other) {
	std::cout<<"AMateria copy assignment operator called"<<std::endl;
	if (this != &other ) {
		this->_type = other._type;
	}
	return (*this);
}

AMateria::~AMateria() {
	std::cout<<"AMateria destructor called"<<std::endl;
}

const std::string&	AMateria::getType() const {
	return (_type);
}

void	AMateria::use(ICharacter &target) {
	std::cout<<"Use member function from AMateria abstract class called"<<std::endl;
	std::cout<<"USE MATERIA ON "<<&target<<std::endl;
}

