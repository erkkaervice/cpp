/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:17:05 by eala-lah          #+#    #+#             */
/*   Updated: 2025/10/15 16:20:34 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap Default constructor called for " << this->_name << std::endl;
}

FragTrap::FragTrap(FragTrap const & src) : ClapTrap(src)
{
	std::cout << "FragTrap Copy constructor called" << std::endl;
	*this = src;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap Destructor called for " << this->_name << std::endl;
}

FragTrap & FragTrap::operator=(FragTrap const & rhs)
{
	std::cout << "FragTrap Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDamage = rhs._attackDamage;
	}
	return *this;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap Name constructor called for " << this->_name << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->_name << " requests a positive high five!" << std::endl;
}
