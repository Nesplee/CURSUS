/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 18:46:30 by dinguyen          #+#    #+#             */
/*   Updated: 2025/09/07 19:02:58 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	std::cout<<"Brain constructor called"<<std::endl;
}

Brain::Brain(const Brain& other) {
	std::cout<<"Brain copy constructor called"<<std::endl;
	int	i = 0;
	while (i < 100) {
		this->ideas[i] = other.ideas[i];
		i++;
	}
}

Brain& Brain::operator=(const Brain& other) {
	std::cout<<"Brain assignment operator called"<<std::endl;
	if (this != &other) {
		int	i = 0;
		while (i < 100) {
			this->ideas[i] = other.ideas[i];
			i++;
		}
	}
	return (*this);
}

Brain::~Brain() {
	std::cout<<"Brain destructor called"<<std::endl;
}

std::string	Brain::getIdea(int index) const {
	if (index >= 0 && index < 100)
		return (ideas[index]);
	return ("");
}

void	Brain::setIdea(int index, const std::string& idea) {
	if (index >= 0 && index < 100)
		ideas[index] = idea;
}
