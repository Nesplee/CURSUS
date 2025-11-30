/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 07:17:37 by dinguyen          #+#    #+#             */
/*   Updated: 2025/11/30 08:08:35 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>
# include "AForm.hpp"

class	AForm;
class	Bureaucrat {

public:
	Bureaucrat();
	Bureaucrat(const std::string &name, int grade);
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat&	operator=(const Bureaucrat &other);
	~Bureaucrat();

	const std::string&	getName() const;
	int					getGrade() const;
	void				incrementGrade();
	void				decrementGrade();
	void				signAForm(AForm &f);

	void				executeAForm(const AForm &f) const;

	class	GradeTooHighE : public std::exception {
		public:
			virtual const char* what() const throw();
	};

	class	GradeTooLowE : public std::exception {
		public:
			virtual const char* what() const throw();
	};

private:
	const std::string	_name;
	int					_grade;

};

std::ostream&	operator<<(std::ostream &os, const Bureaucrat &b);

#endif
