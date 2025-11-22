/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 15:13:11 by dinguyen          #+#    #+#             */
/*   Updated: 2025/11/22 16:02:19 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class	ScavTrap : virtual public ClapTrap {

public:
	ScavTrap(const std::string &name);
	ScavTrap(const ScavTrap &other);
	ScavTrap&	operator=(const ScavTrap &other);
	~ScavTrap();

	void	attack(const std::string &target);
	void	guardGate(void);

private:
	bool	_keeperMode;
};

#endif
