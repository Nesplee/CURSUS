/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:06:53 by dinguyen          #+#    #+#             */
/*   Updated: 2025/11/25 11:12:13 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class	WrongCat : public WrongAnimal {

public:
	WrongCat();
	WrongCat(const WrongCat &other);
	WrongCat&	operator=(const WrongCat &other);
	~WrongCat();

	void	makeSound() const;

};

#endif
