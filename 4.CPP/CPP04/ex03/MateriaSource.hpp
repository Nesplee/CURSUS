/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 13:35:19 by dinguyen          #+#    #+#             */
/*   Updated: 2025/11/26 14:10:54 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class	MateriaSource : public IMateriaSource {

private:
	AMateria*	_knownMaterias[4];

public:
	MateriaSource();
	MateriaSource(const MateriaSource &other);
	MateriaSource&	operator=(const MateriaSource &other);
	~MateriaSource();

	void		learnMateria(AMateria* m);
	AMateria*	createMateria(const std::string &type);
};

#endif
