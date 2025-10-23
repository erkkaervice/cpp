/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 15:46:37 by eala-lah          #+#    #+#             */
/*   Updated: 2025/10/23 15:47:10 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int	main(void)
{
	Bureaucrat	boss("Boss", 1);
	Bureaucrat	mid("Mid", 70);
	Bureaucrat	peon("Peon", 148);

	ShrubberyCreationForm	shrub("garden");
	RobotomyRequestForm		robot("Bender");
	PresidentialPardonForm	pardon("Ford");

	std::cout << "\n--- FORM STATUS ---" << std::endl;
	std::cout << shrub << std::endl;
	std::cout << robot << std::endl;
	std::cout << pardon << std::endl;

	std::cout << "\n--- PEON ACTIONS ---" << std::endl;
	peon.signForm(shrub);
	peon.executeForm(shrub);
	peon.signForm(robot);
	peon.executeForm(robot);
	peon.signForm(pardon);
	peon.executeForm(pardon);

	std::cout << "\n--- MID ACTIONS ---" << std::endl;
	mid.signForm(shrub);
	mid.executeForm(shrub);
	mid.signForm(robot);
	mid.executeForm(robot);
	mid.signForm(pardon);
	mid.executeForm(pardon);

	std::cout << "\n--- BOSS ACTIONS ---" << std::endl;
	boss.signForm(shrub);
	boss.executeForm(shrub);
	boss.signForm(robot);
	boss.executeForm(robot);
	boss.signForm(pardon);
	boss.executeForm(pardon);

	std::cout << "\n--- EXECUTE UNSIGNED ---" << std::endl;
	PresidentialPardonForm	unsignedPardon("Arthur");
	boss.executeForm(unsignedPardon);

	return 0;
}
