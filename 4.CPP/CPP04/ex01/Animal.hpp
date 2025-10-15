/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 10:16:04 by dinguyen          #+#    #+#             */
/*   Updated: 2025/09/07 21:46:09 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>
# include "Brain.hpp"

class	Animal
{

protected:
	std::string	_type;

public:
	Animal();
	Animal(const Animal& other);
	Animal& operator=(const Animal& other);
	Animal(const std::string &type);
	virtual ~Animal();
	virtual void	makeSound() const;
	std::string	getType() const;

};

#endif
