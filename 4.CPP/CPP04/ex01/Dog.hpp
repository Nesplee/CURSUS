/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 13:14:20 by dinguyen          #+#    #+#             */
/*   Updated: 2025/09/07 21:32:58 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include <iostream>
# include <string>

class	Dog : public Animal
{

private:
	Brain*	_brain;

public:
	Dog();
	Dog(const Dog& other);
	Dog& operator=(const Dog& other);

	virtual ~Dog();
	virtual void	makeSound() const;

};

#endif
