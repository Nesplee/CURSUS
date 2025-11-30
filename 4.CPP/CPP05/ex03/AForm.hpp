/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 10:45:39 by dinguyen          #+#    #+#             */
/*   Updated: 2025/11/28 16:11:01 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AForm_HPP
# define AForm_HPP

# include "Bureaucrat.hpp"

class	Bureaucrat;
class	AForm {

private:
	const std::string	_name;
	bool				_isSigned;
	const int			_gradeToSign;
	const int			_gradeToExec;

protected:
	void	_checkExecution(const Bureaucrat &b) const;

public:
	AForm();
	AForm(const std::string &name, const int signG, const int execG);
	AForm(const AForm &other);
	AForm&	operator=(const AForm &other);
	virtual ~AForm();

	bool				getIsSigned() const;
	int					getGradeToSign() const;
	int					getGradeToExec() const;
	const std::string&	getName() const;
	void				beSigned(const Bureaucrat &b);
	virtual void		execute(const Bureaucrat &b) const = 0;

	class	GradeTooHighE : public std::exception {
		public:
			virtual const char*	what() const throw();
	};

	class	GradeTooLowE : public std::exception {
		public:
			virtual const char*	what() const throw();
	};

	class	NotSignedE : public std::exception {
		public:
			virtual const char*	what() const throw();
	};
};

std::ostream&	operator<<(std::ostream &os, const AForm &f);

#endif
