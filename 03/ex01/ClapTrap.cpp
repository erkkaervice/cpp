/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:14:27 by eala-lah          #+#    #+#             */
/*   Updated: 2025/10/15 16:15:16 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap Default constructor called for " << this->_name << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & src)
{
	std::cout << "ClapTrap Copy constructor called" << std::endl;
	*this = src;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap Destructor called for " << this->_name << std::endl;
}

ClapTrap & ClapTrap::operator=(ClapTrap const & rhs)
{
	std::cout << "ClapTrap Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDamage = rhs._attackDamage;
	}
	return *this;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap Name constructor called for " << this->_name << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->_energyPoints <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " has no energy to attack!" << std::endl;
		return;
	}
	if (this->_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " is too damaged to attack!" << std::endl;
		return;
	}

	this->_energyPoints--;
	std::cout << "ClapTrap " << this->_name << " attacks " << target
			  << ", causing " << this->_attackDamage << " points of damage!"
			  << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " is already knocked out!" << std::endl;
		return;
	}

	this->_hitPoints -= amount;
	std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage!" << std::endl;

	if (this->_hitPoints <= 0)
		std::cout << "ClapTrap " << this->_name << " has been knocked out!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " has no energy to repair!" << std::endl;
		return;
	}
	if (this->_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " is too damaged to repair!" << std::endl;
		return;
	}

	this->_energyPoints--;
	this->_hitPoints += amount;
	std::cout << "ClapTrap " << this->_name << " repairs itself for " << amount << " hit points!" << std::endl;
}

int	ClapTrap::getHitPoints(void) const
{
	return this->_hitPoints;
}

int	ClapTrap::getEnergyPoints(void) const
{
	return this->_energyPoints;
}

int	ClapTrap::getAttackDamage(void) const
{
	return this->_attackDamage;
}
