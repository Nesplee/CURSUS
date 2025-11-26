/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 09:55:42 by dinguyen          #+#    #+#             */
/*   Updated: 2025/11/25 16:57:20 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class	Cat : public AAnimal {

private:
	Brain*	_brain;

public:
	Cat();
	Cat(const Cat &other);
	Cat&	operator=(const Cat &other);
	~Cat();

	void	makeSound() const;
	std::string	getIdea(int index) const;
	void		setIdea(int index, const std::string &idea);

};


#endif
