/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 10:45:39 by dinguyen          #+#    #+#             */
/*   Updated: 2025/11/28 15:36:47 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class	Bureaucrat;
class	Form {

private:
	const std::string	_name;
	bool				_isSigned;
	const int			_gradeToSign;
	const int			_gradeToExec;

public:
	Form();
	Form(const std::string &name, const int signG, const int execG);
	Form(const Form &other);
	Form&	operator=(const Form &other);
	~Form();

	bool				getIsSigned() const;
	int					getGradeToSign() const;
	int					getGradeToExec() const;
	const std::string&	getName() const;
	void				beSigned(const Bureaucrat &b);

	class	GradeTooHighE : public std::exception {
		public:
			virtual const char*	what() const throw();
	};

	class	GradeTooLowE : public std::exception {
		public:
			virtual const char*	what() const throw();
	};
};

std::ostream&	operator<<(std::ostream &os, const Form &f);

#endif
