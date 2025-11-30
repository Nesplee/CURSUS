/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 09:48:31 by dinguyen          #+#    #+#             */
/*   Updated: 2025/11/30 11:21:07 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class	AForm;
class	Intern {


public:
	Intern();
	Intern(const Intern &other);
	Intern&	operator=(const Intern &other);
	~Intern();

	static AForm*	createShrubbery(const std::string &target);
	static AForm*	createRobotomy(const std::string &target);
	static AForm*	createPresidential(const std::string &target);
	AForm*	makeForm(const std::string &formName, const std::string &target);

	class	InvalidFormNameE : public std::exception {
		public:
			virtual const char*	what() const throw();
	};
};

#endif
