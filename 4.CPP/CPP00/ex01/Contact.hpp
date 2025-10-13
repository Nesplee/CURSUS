/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 09:32:26 by dinguyen          #+#    #+#             */
/*   Updated: 2025/10/06 10:46:05 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

class	Contact {

private:
	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickName;
	std::string	_phoneNumber;
	std::string	_darkestSecret;

	std::string	_getInput(const std::string &prompt) const;
	bool		_isValidNumber(const std::string &number) const;
	std::string	_getPhoneNumber(const std::string &prompt) const;
	void		_setFirstName(const std::string &name);
	void		_setLastName(const std::string &name);
	void		_setNickName(const std::string &name);
	void		_setPhoneNumber(const std::string &number);
	void		_setDarkestSecret(const std::string &secret);

public:
	Contact();
	~Contact();
	std::string	getFirstName() const;
	std::string	getLastName() const;
	std::string	getNickName() const;
	std::string	getPhoneNumber() const;
	std::string	getDarkestSecret() const;
	void		displayContact() const;
	void		recordContact();

};

#endif
