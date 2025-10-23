/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 15:43:06 by eala-lah          #+#    #+#             */
/*   Updated: 2025/10/23 15:43:32 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void) : _name("DefaultForm"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {}

AForm::AForm(std::string const& name, int gradeToSign, int gradeToExecute) :
	_name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& src) :
	_name(src._name), _isSigned(src._isSigned), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute) {}

AForm::~AForm() {}

AForm& AForm::operator=(const AForm& rhs)
{
	if (this != &rhs)
	{
		_isSigned = rhs._isSigned;
	}
	return *this;
}

std::string const&	AForm::getName(void) const
{
	return _name;
}

bool	AForm::getIsSigned(void) const
{
	return _isSigned;
}

int	AForm::getGradeToSign(void) const
{
	return _gradeToSign;
}

int	AForm::getGradeToExecute(void) const
{
	return _gradeToExecute;
}

void	AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw AForm::GradeTooLowException();
	_isSigned = true;
}

void	AForm::checkExecution(Bureaucrat const& executor) const
{
	if (!this->getIsSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "AForm::GradeTooHighException";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "AForm::GradeTooLowException";
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return "AForm::FormNotSignedException";
}

std::ostream&	operator<<(std::ostream& out, const AForm& form)
{
	out << "AForm: " << form.getName()
		<< ", Signed: " << (form.getIsSigned() ? "Yes" : "No")
		<< ", Grade to Sign: " << form.getGradeToSign()
		<< ", Grade to Execute: " << form.getGradeToExecute();
	return out;
}
