/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 15:21:33 by eala-lah          #+#    #+#             */
/*   Updated: 2025/10/23 15:22:01 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

void	testValidSigning()
{
	std::cout << "--- Testing Valid Signing ---" << std::endl;
	try
	{
		Bureaucrat	signer("Signer", 50);
		Form		formA("FormA", 75, 100);

		std::cout << signer << std::endl;
		std::cout << formA << std::endl;
		signer.signForm(formA);
		std::cout << formA << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Unexpected exception: " << e.what() << std::endl;
	}
}

void	testInvalidSigning()
{
	std::cout << "\n--- Testing Invalid Signing (Grade Too Low) ---" << std::endl;
	try
	{
		Bureaucrat	weakling("Weakling", 100);
		Form		formB("FormB", 50, 80);

		std::cout << weakling << std::endl;
		std::cout << formB << std::endl;
		weakling.signForm(formB);
		std::cout << formB << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Unexpected exception: " << e.what() << std::endl;
	}
}

void	testInvalidFormConstruction()
{
	std::cout << "\n--- Testing Invalid Form Construction ---" << std::endl;
	try
	{
		std::cout << "Trying grades 0, 100: ";
		Form	tooHigh("HighForm", 0, 100);
		std::cout << tooHigh << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}
	try
	{
		std::cout << "Trying grades 100, 151: ";
		Form	tooLow("LowForm", 100, 151);
		std::cout << tooLow << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}
}

int	main(void)
{
	testValidSigning();
	testInvalidSigning();
	testInvalidFormConstruction();

	return 0;
}
