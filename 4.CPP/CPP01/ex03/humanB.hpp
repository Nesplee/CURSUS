/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   humanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 10:18:51 by dinguyen          #+#    #+#             */
/*   Updated: 2025/08/16 10:50:09 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "weapon.hpp"
# include <iostream>
# include <string>

class	HumanB
{

public:
	HumanB(const std::string &name);
	~HumanB();
	void	attack(void) const ;
	void	setWeapon(Weapon& weaponType);

private:
	Weapon*				_weaponType;
	const std::string	_name;
};
#endif
