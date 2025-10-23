/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 15:20:27 by eala-lah          #+#    #+#             */
/*   Updated: 2025/10/23 15:21:08 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class	Form
{
	private:
		std::string const	_name;
		bool			_isSigned;
		int const		_gradeToSign;
		int const		_gradeToExecute;

	public:
		Form(void);
		Form(std::string const& name, int gradeToSign, int gradeToExecute);
		Form(const Form& src);
		~Form();

		Form& operator=(const Form& rhs);

		std::string const&	getName(void) const;
		bool			getIsSigned(void) const;
		int			getGradeToSign(void) const;
		int			getGradeToExecute(void) const;

		void	beSigned(const Bureaucrat& bureaucrat);

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
};

std::ostream&	operator<<(std::ostream& out, const Form& form);

#endif
