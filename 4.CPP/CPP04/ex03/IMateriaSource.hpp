/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 12:15:27 by dinguyen          #+#    #+#             */
/*   Updated: 2025/11/26 13:32:29 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

# include <string>
# include "AMateria.hpp"

class	IMateriaSource {

public:
	virtual	~IMateriaSource();
	virtual void		learnMateria(AMateria*) = 0;
	virtual AMateria*	createMateria(const std::string &type) = 0;
};

#endif
