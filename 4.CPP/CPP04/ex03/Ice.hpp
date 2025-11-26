/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 11:24:48 by dinguyen          #+#    #+#             */
/*   Updated: 2025/11/26 11:29:51 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class	Ice : public AMateria {

public:
	Ice();
	Ice(const Ice &other);
	Ice&	operator=(const Ice &other);
	~Ice();

	AMateria*	clone() const;
	void		use(ICharacter &target);

};

#endif
