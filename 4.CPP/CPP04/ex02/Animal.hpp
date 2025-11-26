/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 19:08:09 by dinguyen          #+#    #+#             */
/*   Updated: 2025/11/25 16:54:44 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class	AAnimal {

protected:
	std::string	_type;

public:
	AAnimal();
	AAnimal(const AAnimal &other);
	AAnimal&	operator=(const AAnimal &other);
	virtual	~AAnimal();
	std::string	getType() const;

	virtual void	makeSound() const = 0;
};

#endif
