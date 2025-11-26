/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 11:48:46 by dinguyen          #+#    #+#             */
/*   Updated: 2025/11/26 11:59:23 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class	Cure : public AMateria {

public:
	Cure();
	Cure(const Cure &other);
	Cure&	operator=(const Cure &other);
	~Cure();

	AMateria*	clone() const;
	void		use(ICharacter &target);
};

#endif
