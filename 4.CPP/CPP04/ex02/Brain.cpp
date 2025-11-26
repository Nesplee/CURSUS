/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:53:39 by dinguyen          #+#    #+#             */
/*   Updated: 2025/11/25 16:08:35 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	std::cout<<"Brain default constructor called"<<std::endl;
}

Brain::Brain(const Brain &other)  {
	std::cout<<"Brain copy constuctor called"<<std::endl;
	for (int i = 0; i < 100; i++) {
		_ideas[i] = other._ideas[i];
	}
}

Brain&	Brain::operator=(const Brain &other) {
	std::cout<<"Brain copy assignment operator called"<<std::endl;
	if (this != &other) {
		for (int i = 0; i < 100; i++) {
			this->_ideas[i] = other._ideas[i];
		}
	}
	return (*this);
}

Brain::~Brain() {
	std::cout<<"Brain destructor called"<<std::endl;
}

std::string	Brain::getIdea(int index) const {
	if (index >= 0 && index < 100) {
		if (_ideas[index].empty())
			return ("No Idea found in that empty cell of the brainzZZZzzzZ");
		return (_ideas[index]);
	}
	return ("InvalidindexxxforBrainIdeasdsdeaffd");
}

void	Brain::setIdea(int index, const std::string &idea) {
	_ideas[index] = idea;
}

