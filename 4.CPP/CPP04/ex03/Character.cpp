/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 12:03:58 by dinguyen          #+#    #+#             */
/*   Updated: 2025/11/30 21:05:09 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() {
	std::cout<<"Character default constructor called"<<std::endl;
	for (int i = 0; i < 4; i++)
		_inventory[i] = 0;
	for (int i = 0; i < 100; i++)
		_floorItems[i] = 0;
	_floorCount = 0;
	_name = "";
}

Character::Character(const std::string &name) : _name(name) {
	std::cout<<"Character default constructor called"<<std::endl;
	for (int i = 0; i < 4; i++)
		_inventory[i] = 0;
	for (int i = 0; i < 100; i++)
		_floorItems[i] = 0;
	_floorCount = 0;
}

Character::Character(const Character &other) {
	std::cout<<"Character copy constructor called"<<std::endl;
	_name = other._name;
	_floorCount = other._floorCount;
	for (int i = 0; i < 4; i++) {
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
		else
			_inventory[i] = 0;
	}
	for (int i = 0; i < _floorCount; i++) {
		if (other._floorItems[i])
			_floorItems[i] = other._floorItems[i]->clone();
		else
			_floorItems[i] = 0;
	}
	for (int i = _floorCount; i < 100; i++)
		_floorItems[i] = 0;
}

Character&	Character::operator=(const Character &other) {
	std::cout<<"Character copy assignment operator called"<<std::endl;
	if (this != &other) {
		for (int i = 0; i < 4; i++) {
			if (this->_inventory[i]) {
					delete _inventory[i];
					_inventory[i] = 0;
				}
			}
		for (int i = other._floorCount; i < _floorCount; ++i) {
			if (_floorItems[i]) {
				delete _floorItems[i];
				_floorItems[i] = 0;
			}
		}
		for (int i = 0; i < 4; ++i) {
			if (other._inventory[i])
				_inventory[i] = other._inventory[i]->clone();
			else
				_inventory[i] = 0;
		}
		_floorCount = other._floorCount;
		for (int i = 0; i < _floorCount; ++i) {
			if (other._floorItems[i])
				_floorItems[i] = other._floorItems[i]->clone();
			else
				_floorItems[i] = 0;
		}
		for (int i = _floorCount; i < 100; ++i) {
			_floorItems[i] = 0;
		}
		_name = other._name;
	}
	return (*this);
}

Character::~Character() {
	for (int i = 0; i < 4; i++) {
		if (_inventory[i])
			delete _inventory[i];
	}
	for (int i = 0; i < _floorCount; i++) {
		if (_floorItems[i])
			delete _floorItems[i];
	}
	std::cout<<"Character destructor called"<<std::endl;
}

const std::string&	Character::getName() const {
	return (_name);
}

int		Character::_freeSpaceIndex() const {
	for (int i = 0; i < 4; i++) {
		if (_inventory[i] == 0)
			return (i);
	}
	std::cout<<"No space found on inventory"<<std::endl;
	return (-1);
}

void	Character::equip(AMateria *m) {
	if (!m)
		return ;
	int index = _freeSpaceIndex();
	if (index != -1) {
		for (int i = 0; i < _floorCount; ++i) {
			if (_floorItems[i] == m) {
				_floorItems[i] = _floorItems[_floorCount - 1];
				_floorItems[_floorCount - 1] = 0;
				--_floorCount;
				break;
			}
		}
		_inventory[index] = m;
		std::cout<<"item equipped"<<std::endl;
	} else if (_floorCount < 100) {
		_floorItems[_floorCount++] = m;
		std::cout<<"Item on the floor"<<std::endl;
	}
}
void	Character::unequip(int index) {
	if (index < 0 || index >= 4  || !_inventory[index])
		return ;
	if (_floorCount < 100) {
		_floorItems[_floorCount++] = _inventory[index];
		_inventory[index] = 0;
		std::cout<<"Item on slot "<<index<<" has been put on the floor"<<std::endl;
	}
}

void	Character::use(int index, ICharacter &target) {
	if (index < 0 || index >= 4 || !_inventory[index])
		return ;
	_inventory[index]->use(target);
}

AMateria*	Character::getInventoryItem(int index) const {
	if (index < 0 || index >= 4)
		return (0);
	return (_inventory[index]);
}
