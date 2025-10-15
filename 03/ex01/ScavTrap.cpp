/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:16:08 by eala-lah          #+#    #+#             */
/*   Updated: 2025/10/15 15:42:57 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap Default constructor called for " << this->_name << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const & src) : ClapTrap(src)
{
	std::cout << "ScavTrap Copy constructor called" << std::endl;
	*this = src;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap Destructor called for " << this->_name << std::endl;
}

ScavTrap & ScavTrap::operator=(ScavTrap const & rhs)
{
	std::cout << "ScavTrap Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDamage = rhs._attackDamage;
	}
	return *this;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap Name constructor called for " << this->_name << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->_energyPoints <= 0)
	{
		std::cout << "ScavTrap " << this->_name << " is out of energy!" << std::endl;
		return;
	}
	if (this->_hitPoints <= 0)
	{
		std::cout << "ScavTrap " << this->_name << " is too broken to attack!" << std::endl;
		return;
	}

	this->_energyPoints--;
	std::cout << "ScavTrap " << this->_name << " fiercely attacks " << target
			  << ", dealing " << this->_attackDamage << " points of damage!"
			  << std::endl;
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode." << std::endl;
}
