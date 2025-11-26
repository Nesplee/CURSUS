/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 19:08:09 by dinguyen          #+#    #+#             */
/*   Updated: 2025/11/25 10:24:48 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class	Animal {

protected:
	std::string	_type;

public:
	Animal();
	Animal(const Animal &other);
	Animal&	operator=(const Animal &other);
	virtual	~Animal();
	std::string	getType() const;

	virtual void	makeSound() const;
};

#endif
