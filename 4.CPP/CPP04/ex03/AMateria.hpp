/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 19:44:15 by dinguyen          #+#    #+#             */
/*   Updated: 2025/11/26 14:51:20 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>

class	ICharacter;

class	AMateria {

public:
	AMateria(const std::string &type);
	AMateria(const AMateria &other);
	AMateria&	operator=(const AMateria &other);
	virtual	~AMateria();

	const std::string&	getType() const;
	virtual	AMateria*	clone() const = 0;
	virtual void		use(ICharacter &target);

protected:
	std::string _type;

};

#endif
