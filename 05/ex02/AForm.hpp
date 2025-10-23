/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 15:42:43 by eala-lah          #+#    #+#             */
/*   Updated: 2025/10/23 15:43:05 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class	AForm
{
	private:
		std::string const	_name;
		bool			_isSigned;
		int const		_gradeToSign;
		int const		_gradeToExecute;

	public:
		AForm(void);
		AForm(std::string const& name, int gradeToSign, int gradeToExecute);
		AForm(const AForm& src);
		virtual ~AForm();

		AForm& operator=(const AForm& rhs);

		std::string const&	getName(void) const;
		bool			getIsSigned(void) const;
		int			getGradeToSign(void) const;
		int			getGradeToExecute(void) const;

		void	beSigned(const Bureaucrat& bureaucrat);
		void	checkExecution(Bureaucrat const& executor) const;
		virtual void	execute(Bureaucrat const& executor) const = 0;

		class	GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class	GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class	FormNotSignedException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream&	operator<<(std::ostream& out, const AForm& form);

#endif
