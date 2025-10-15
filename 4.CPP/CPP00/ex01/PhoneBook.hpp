/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:02:56 by dinguyen          #+#    #+#             */
/*   Updated: 2025/10/14 14:58:41 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>
# include <string>

class	PhoneBook {

private:
	Contact	_contacts[8];
	int		_currentSize;
	int		_nextIndex;

	std::string	_formatColumn(const std::string &text) const;
	void		_displayHeader(void) const;
	void		_displayTable(void) const;
	void		_displayContactList(void) const;

public:
	PhoneBook();
	~PhoneBook();

	void	addContact(void);
	void	searchContact(void) const;
};

#endif
