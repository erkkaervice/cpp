/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 15:48:54 by eala-lah          #+#    #+#             */
/*   Updated: 2025/10/23 15:50:15 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int	main(void)
{
	Intern	someRandomIntern;
	AForm*	formPtr;

	std::cout << "--- Testing Intern Form Creation ---" << std::endl;

	formPtr = someRandomIntern.makeForm("robotomy request", "Bender");
	if (formPtr)
	{
		Bureaucrat b("Hermes", 30);
		b.signForm(*formPtr);
		b.executeForm(*formPtr);
		delete formPtr;
		formPtr = NULL;
	}

	std::cout << std::endl;

	formPtr = someRandomIntern.makeForm("presidential pardon", "Ford");
	if (formPtr)
	{
		Bureaucrat b("Zaphod", 1);
		b.signForm(*formPtr);
		b.executeForm(*formPtr);
		delete formPtr;
		formPtr = NULL;
	}

	std::cout << std::endl;

	formPtr = someRandomIntern.makeForm("shrubbery creation", "Home");
	if (formPtr)
	{
		Bureaucrat b("Gardener", 130);
		b.signForm(*formPtr);
		b.executeForm(*formPtr);
		delete formPtr;
		formPtr = NULL;
	}

	std::cout << std::endl;

	formPtr = someRandomIntern.makeForm("unknown form", "Nobody");
	if (formPtr) // This should be NULL
		delete formPtr;

	return 0;
}
