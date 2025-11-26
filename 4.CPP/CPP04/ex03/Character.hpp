/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 12:05:17 by dinguyen          #+#    #+#             */
/*   Updated: 2025/11/26 14:36:33 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

class	Character : public ICharacter {

private:
	std::string		_name;
	AMateria*		_inventory[4];
	AMateria*		_floorItems[100];
	int				_floorCount;
	int				_freeSpaceIndex() const;

public:
	Character();
	Character(const std::string &name);
	Character(const Character &other);
	Character&	operator=(const Character &other);
	~Character();

	const std::string&	getName() const;
	void				equip(AMateria *m);
	void				unequip(int index);
	void				use(int index, ICharacter &target);
	AMateria*			getInventoryItem(int index) const;
};

#endif
