/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 15:21:04 by eala-lah          #+#    #+#             */
/*   Updated: 2025/10/23 15:31:57 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) : _name("DefaultForm"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {}

Form::Form(std::string const& name, int gradeToSign, int gradeToExecute) :
	_name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form& src) :
	_name(src._name), _isSigned(src._isSigned), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute) {}

Form::~Form() {}

Form& Form::operator=(const Form& rhs)
{
	if (this != &rhs)
		_isSigned = rhs._isSigned;
	return *this;
}

std::string const&	Form::getName(void) const
{
	return _name;
}

bool	Form::getIsSigned(void) const
{
	return _isSigned;
}

int	Form::getGradeToSign(void) const
{
	return _gradeToSign;
}

int	Form::getGradeToExecute(void) const
{
	return _gradeToExecute;
}

void	Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw Form::GradeTooLowException();
	_isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Form::GradeTooHighException";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Form::GradeTooLowException";
}

std::ostream&	operator<<(std::ostream& out, const Form& form)
{
	out << "Form: " << form.getName()
		<< ", Signed: " << (form.getIsSigned() ? "Yes" : "No")
		<< ", Grade to Sign: " << form.getGradeToSign()
		<< ", Grade to Execute: " << form.getGradeToExecute();
	return out;
}
