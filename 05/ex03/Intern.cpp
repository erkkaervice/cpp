/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 15:48:08 by eala-lah          #+#    #+#             */
/*   Updated: 2025/10/23 15:54:17 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern(void) {}

Intern::Intern(const Intern& src)
{
	*this = src;
}

Intern::~Intern() {}

Intern& Intern::operator=(const Intern& rhs)
{
	(void)rhs;
	return *this;
}

AForm*	Intern::makeForm(std::string const& formName, std::string const& target)
{
	AForm* newForm = NULL;

	if (formName == "shrubbery creation")
		newForm = new ShrubberyCreationForm(target);
	else if (formName == "robotomy request")
		newForm = new RobotomyRequestForm(target);
	else if (formName == "presidential pardon")
		newForm = new PresidentialPardonForm(target);

	if (newForm)
		std::cout << "Intern creates " << formName << std::endl;
	else
		std::cout << "Intern cannot create form '" << formName << "' because the name is unknown." << std::endl;

	return newForm;
}
