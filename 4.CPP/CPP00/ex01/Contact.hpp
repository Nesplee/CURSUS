/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:02:58 by dinguyen          #+#    #+#             */
/*   Updated: 2025/10/13 15:25:20 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>
# include <cctype>

class	Contact {

private:
	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickName;
	std::string	_phoneNumber;
	std::string	_darkestSecret;

	void		_setFirstName(const std::string &name);
	void		_setLastName(const std::string &name);
	void		_setNickName(const std::string &name);
	void		_setPhoneNumber(const std::string &number);
	void		_setDarkestSecret(const std::string &secret);
	std::string	_getInput(const std::string &prompt) const;
	bool		_isValidPhoneNumber(const std::string &number) const;
	std::string	_getPhoneNumber(const std::string &prompt) const;

public:
	Contact();
	~Contact();
	void		recordContact(void);
	void		displayContact(void) const ;
	std::string	getFirstName(void) const ;
	std::string	getLastName(void) const ;
	std::string	getNickName(void) const ;
	std::string	getPhoneNumber(void) const ;
	std::string	getDarkestSecret(void) const ;
};

#endif
