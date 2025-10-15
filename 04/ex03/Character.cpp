/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:41:10 by eala-lah          #+#    #+#             */
/*   Updated: 2025/10/15 13:41:16 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>

Character::Character(const std::string &n) : name(n)
{
	for (int i = 0; i < 4; i++)
		inventory[i] = nullptr;
	std::cout << "Character constructor called" << std::endl;
}

Character::Character(const Character &other) : name(other.name)
{
	for (int i = 0; i < 4; i++)
		inventory[i] = other.inventory[i] ? other.inventory[i]->clone() : nullptr;
	std::cout << "Character copy constructor called" << std::endl;
}

Character &Character::operator=(const Character &other)
{
	if (this != &other)
	{
		name = other.name;
		for (int i = 0; i < 4; i++)
		{
			delete inventory[i];
			inventory[i] = other.inventory[i] ? other.inventory[i]->clone() : nullptr;
		}
	}
	std::cout << "Character copy assignment called" << std::endl;
	return *this;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
		delete inventory[i];
	std::cout << "Character destructor called" << std::endl;
}

std::string const & Character::getName() const
{
	return name;
}

void Character::equip(AMateria* m)
{
	if (!m)
		return;
	for (int i = 0; i < 4; i++)
	{
		if (!inventory[i])
		{
			inventory[i] = m;
			return;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4)
		inventory[idx] = nullptr;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx < 4 && inventory[idx])
		inventory[idx]->use(target);
}
