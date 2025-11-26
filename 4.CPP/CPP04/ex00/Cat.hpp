/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 09:55:42 by dinguyen          #+#    #+#             */
/*   Updated: 2025/11/25 12:49:33 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class	Cat : public Animal {

protected:

public:
	Cat();
	Cat(const Cat &other);
	Cat&	operator=(const Cat &other);
	~Cat();

	void	makeSound() const;
};


#endif
