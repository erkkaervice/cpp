/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 15:19:30 by eala-lah          #+#    #+#             */
/*   Updated: 2025/10/23 15:21:08 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>

class Form;

class	Bureaucrat
{
	private:
		std::string const	_name;
		int			_grade;

	public:
		Bureaucrat(void);
		Bureaucrat(std::string const& name, int grade);
		Bureaucrat(const Bureaucrat& src);
		~Bureaucrat();

		Bureaucrat& operator=(const Bureaucrat& rhs);

		std::string const&	getName(void) const;
		int			getGrade(void) const;

		void	incrementGrade(void);
		void	decrementGrade(void);

		void	signForm(Form& form);

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

std::ostream&	operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

#endif
