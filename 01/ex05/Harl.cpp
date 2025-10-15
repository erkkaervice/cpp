/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 17:14:04 by eala-lah          #+#    #+#             */
/*   Updated: 2025/10/13 14:31:33 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

Harl::Harl(void) {}
Harl::~Harl(void) {}

void Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl
		<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger." << std::endl
		<< "I really do!" << std::endl
		<< std::endl;
}

void Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl
		<< "I cannot believe adding extra bacon costs more money." << std::endl
		<< "You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl
		<< std::endl;
}

void Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl
		<< "I think I deserve to have some extra bacon for free." << std::endl
		<< "I've been coming for years whereas you started working here since last month." << std::endl
		<< std::endl;
}

void Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl
		<< "This is unacceptable, I want to speak to the manager now." << std::endl
		<< std::endl;
}

void Harl::complain(std::string level)
{
	typedef void (Harl::*HarlFn)(void);
	HarlFn funcs[] = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
	std::string levels[] = { "DEBUG", "INFO", "WARNING", "ERROR" };

	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			(this->*funcs[i])();
			return;
		}
	}
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}
