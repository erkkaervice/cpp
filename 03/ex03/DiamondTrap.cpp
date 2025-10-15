/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:24:37 by eala-lah          #+#    #+#             */
/*   Updated: 2025/10/15 16:24:58 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap("Default_clap_name"), ScavTrap(), FragTrap()
{
	this->_name = "Default";
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	std::cout << "DiamondTrap Default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	this->_name = name;
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	std::cout << "DiamondTrap Name constructor called for " << this->_name << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const & src) : ClapTrap(src), ScavTrap(src), FragTrap(src)
{
	std::cout << "DiamondTrap Copy constructor called" << std::endl;
	*this = src;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap Destructor called for " << this->_name << std::endl;
}

DiamondTrap & DiamondTrap::operator=(DiamondTrap const & rhs)
{
	std::cout << "DiamondTrap Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs._name;
		ClapTrap::_name = rhs.ClapTrap::_name;
		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDamage = rhs._attackDamage;
	}
	return *this;
}

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "My DiamondTrap name is " << this->_name
			  << " and my ClapTrap name is " << ClapTrap::_name << std::endl;
}
