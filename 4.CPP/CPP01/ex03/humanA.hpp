/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   humanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 10:18:49 by dinguyen          #+#    #+#             */
/*   Updated: 2025/10/14 15:19:47 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMAN_HPP

#include <iostream>
#include <string>
#include "weapon.hpp"

class	HumanA
{

public:
	HumanA(Weapon& weaponType, const std::string &name);
	~HumanA();
	void	attack(void);

private:
	Weapon&				_weaponType;
	const std::string	_name;
};

#endif
