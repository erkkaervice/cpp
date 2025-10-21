/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:16:08 by eala-lah          #+#    #+#             */
/*   Updated: 2025/10/21 14:03:11 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap Default constructor called for " << _name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& src) : ClapTrap(src)
{
	std::cout << "ScavTrap Copy constructor called" << std::endl;
	*this = src;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap Destructor called for " << _name << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& rhs)
{
	std::cout << "ScavTrap Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		_name = rhs._name;
		_hitPoints = rhs._hitPoints;
		_energyPoints = rhs._energyPoints;
		_attackDamage = rhs._attackDamage;
	}
	return *this;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap Name constructor called for " << _name << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (_energyPoints <= 0)
	{
		std::cout << "ScavTrap " << _name << " is out of energy!" << std::endl;
		return;
	}
	if (_hitPoints <= 0)
	{
		std::cout << "ScavTrap " << _name << " is too broken to attack!" << std::endl;
		return;
	}

	_energyPoints--;
	std::cout << "ScavTrap " << _name << " fiercely attacks " << target
			  << ", dealing " << _attackDamage << " points of damage!"
			  << std::endl;
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << _name << " is now in Gate keeper mode." << std::endl;
}
