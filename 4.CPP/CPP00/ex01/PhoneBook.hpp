/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 11:05:14 by dinguyen          #+#    #+#             */
/*   Updated: 2025/10/06 11:28:42 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include "Contact.hpp"

class	PhoneBook {

private:
	Contact	_contacts[8];
	int		_currentSize;
	int		_nextIndex;
	std::string	_formatColumn(const std::string &text) const;
	void		_displayHeader() const;
	void		_displayTable() const;
	void		_displayContactList() const;

public:
	PhoneBook();
	~PhoneBook();
	void	addContact();
	void	searchContact();

};

#endif
