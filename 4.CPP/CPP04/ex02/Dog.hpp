/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 10:29:05 by dinguyen          #+#    #+#             */
/*   Updated: 2025/11/25 16:57:38 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class	Dog : public AAnimal {

private:
	Brain*	_brain;

public:
	Dog();
	Dog(const Dog &other);
	Dog&	operator=(const Dog &other);
	~Dog();

	void	makeSound() const;
	std::string	getIdea(int index) const;
	void		setIdea(int index, const std::string &idea);

};

#endif
