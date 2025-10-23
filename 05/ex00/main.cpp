/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 15:07:54 by eala-lah          #+#    #+#             */
/*   Updated: 2025/10/23 15:18:16 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

void	testValidBureaucrats()
{
	std::cout << "--- Testing Valid Bureaucrats ---" << std::endl;
	try
	{
		Bureaucrat	valid1("Hermes", 37);
		std::cout << valid1 << std::endl;
		Bureaucrat	valid2("High", 1);
		std::cout << valid2 << std::endl;
		Bureaucrat	valid3("Low", 150);
		std::cout << valid3 << std::endl;

		valid1.incrementGrade();
		std::cout << "After increment: " << valid1 << std::endl;
		valid1.decrementGrade();
		std::cout << "After decrement: " << valid1 << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}
}

void	testInvalidConstruction()
{
	std::cout << "\n--- Testing Invalid Construction ---" << std::endl;
	try
	{
		std::cout << "Trying grade 0: ";
		Bureaucrat	tooHigh("Zeus", 0);
		std::cout << tooHigh << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}

	try
	{
		std::cout << "Trying grade 151: ";
		Bureaucrat	tooLow("Hades", 151);
		std::cout << tooLow << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}
}

void	testInvalidGradeChanges()
{
	std::cout << "\n--- Testing Invalid Grade Changes ---" << std::endl;
	try
	{
		Bureaucrat	boss("Boss", 1);
		std::cout << boss << std::endl;
		std::cout << "Trying to increment grade 1: ";
		boss.incrementGrade();
		std::cout << boss << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat	peon("Peon", 150);
		std::cout << peon << std::endl;
		std::cout << "Trying to decrement grade 150: ";
		peon.decrementGrade();
		std::cout << peon << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}
}

void	testCopyAndAssignment()
{
	std::cout << "\n--- Testing Copy/Assignment ---" << std::endl;
	Bureaucrat	original("Original", 50);
	Bureaucrat	copy(original);
	Bureaucrat	assigned("Assigned", 100);

	std::cout << "Original: " << original << std::endl;
	std::cout << "Copy:     " << copy << std::endl;
	std::cout << "Assigned (before): " << assigned << std::endl;

	assigned = original;
	std::cout << "Assigned (after):  " << assigned << std::endl;

}

int	main(void)
{
	testValidBureaucrats();
	testInvalidConstruction();
	testInvalidGradeChanges();
	testCopyAndAssignment();

	return 0;
}
