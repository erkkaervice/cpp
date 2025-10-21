/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:14:27 by eala-lah          #+#    #+#             */
/*   Updated: 2025/10/21 14:03:53 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap Default constructor called for " << _name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& src)
{
	std::cout << "ClapTrap Copy constructor called" << std::endl;
	*this = src;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap Destructor called for " << _name << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& rhs)
{
	std::cout << "ClapTrap Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		_name = rhs._name;
		_hitPoints = rhs._hitPoints;
		_energyPoints = rhs._energyPoints;
		_attackDamage = rhs._attackDamage;
	}
	return *this;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap Name constructor called for " << _name << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (_energyPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " has no energy to attack!" << std::endl;
		return;
	}
	if (_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " is too damaged to attack!" << std::endl;
		return;
	}

	_energyPoints--;
	std::cout << "ClapTrap " << _name << " attacks " << target
			  << ", causing " << _attackDamage << " points of damage!"
			  << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " is already knocked out!" << std::endl;
		return;
	}

	_hitPoints -= amount;
	std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!" << std::endl;

	if (_hitPoints <= 0)
		std::cout << "ClapTrap " << _name << " has been knocked out!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_energyPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " has no energy to repair!" << std::endl;
		return;
	}
	if (_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " is too damaged to repair!" << std::endl;
		return;
	}

	_energyPoints--;
	_hitPoints += amount;
	std::cout << "ClapTrap " << _name << " repairs itself for " << amount << " hit points!" << std::endl;
}

int	ClapTrap::getHitPoints(void) const
{
	return _hitPoints;
}

int	ClapTrap::getEnergyPoints(void) const
{
	return _energyPoints;
}

int	ClapTrap::getAttackDamage(void) const
{
	return _attackDamage;
}
