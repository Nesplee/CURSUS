/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 13:35:10 by dinguyen          #+#    #+#             */
/*   Updated: 2025/11/30 20:49:38 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	std::cout<<"MateriaSource default constructor called"<<std::endl;
	for (int i = 0; i < 4; i++)
		_knownMaterias[i] = 0;
}

MateriaSource::MateriaSource(const MateriaSource &other) {
	std::cout<<"MateriaSource copy constructor called"<<std::endl;
	for (int i = 0; i < 4; i++) {
		if (other._knownMaterias[i])
			this->_knownMaterias[i] = other._knownMaterias[i]->clone();
		else
			this->_knownMaterias[i] = 0;
	}
}

MateriaSource&	MateriaSource::operator=(const MateriaSource &other) {
	std::cout<<"MateriaSource copy assignment operator called"<<std::endl;
	if (this != &other ) {
		for (int i = 0; i < 4; i++) {
			if (other._knownMaterias[i]) {
				if (_knownMaterias[i])
					delete _knownMaterias[i];
				_knownMaterias[i] = other._knownMaterias[i]->clone();
			} else {
				if (_knownMaterias[i])
					delete _knownMaterias[i];
				_knownMaterias[i] = 0;
			}
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++) {
		if (_knownMaterias[i])
			delete _knownMaterias[i];
	}
	std::cout<<"MateriaSource destructor called"<<std::endl;
}

void	MateriaSource::learnMateria(AMateria* m) {
	if (!m)
		return ;
	for (int i = 0; i < 4; i++) {
		if (!_knownMaterias[i]) {
			_knownMaterias[i] = m->clone();
			delete m;
			return ;
		}
	}
	std::cout<<"No available slot to learn Materia "<<m->getType()<<std::endl;
	delete m;
}

AMateria*	MateriaSource::createMateria(const std::string &type) {
	for (int i = 0; i < 4; i++) {
		if (_knownMaterias[i] && _knownMaterias[i]->getType() == type) {
			AMateria*	copy = _knownMaterias[i]->clone();
			return (copy);
		}
	}
	return (0);
}
