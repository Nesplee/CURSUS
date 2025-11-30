/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 16:27:04 by dinguyen          #+#    #+#             */
/*   Updated: 2025/11/30 07:13:55 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <fstream>

class	Bureaucrat;
class	ShrubberyCreationForm : public AForm {

private:
	std::string	_target;

public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string &target);
	ShrubberyCreationForm(const ShrubberyCreationForm &other);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm &other);
	virtual ~ShrubberyCreationForm();
	void	execute(const Bureaucrat &b) const;

	class	OpenFileE : public std::exception {
		public:
			virtual const char*	what() const throw();
	};
};

#endif
