/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:41:10 by eala-lah          #+#    #+#             */
/*   Updated: 2025/10/21 18:43:33 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>

Character::Character(void) : _name("Default"), _floorCount(0)
{
	std::cout << "Character: Default constructor called" << std::endl;
	for (int i = 0; i < INV_SIZE; i++)
		_inventory[i] = 0;
	for (int i = 0; i < FLOOR_SIZE; i++)
		_floor[i] = 0;
}

Character::Character(std::string const& name) : _name(name), _floorCount(0)
{
	std::cout << "Character: Name constructor called for " << _name << std::endl;
	for (int i = 0; i < INV_SIZE; i++)
		_inventory[i] = 0;
	for (int i = 0; i < FLOOR_SIZE; i++)
		_floor[i] = 0;
}

Character::Character(const Character& other)
{
	std::cout << "Character: Copy constructor called for " << other._name << std::endl;
	_name = other._name;
	_floorCount = 0;
	for (int i = 0; i < FLOOR_SIZE; i++)
		_floor[i] = 0;
	for (int i = 0; i < INV_SIZE; i++)
	{
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
		else
			_inventory[i] = 0;
	}
}

Character& Character::operator=(const Character& other)
{
	std::cout << "Character: Copy assignment operator called for " << other._name << std::endl;
	if (this != &other)
	{
		_name = other._name;
		for (int i = 0; i < INV_SIZE; i++)
		{
			delete _inventory[i];
			if (other._inventory[i])
				_inventory[i] = other._inventory[i]->clone();
			else
				_inventory[i] = 0;
		}
	}
	return *this;
}

Character::~Character()
{
	std::cout << "Character: Destructor called for " << _name << std::endl;
	for (int i = 0; i < INV_SIZE; i++)
		delete _inventory[i];
	for (int i = 0; i < _floorCount; i++)
		delete _floor[i];
}

std::string const&	Character::getName(void) const
{
	return _name;
}

void	Character::equip(AMateria* m)
{
	if (!m)
	{
		std::cout << _name << " tried to equip nothing." << std::endl;
		return;
	}
	for (int i = 0; i < INV_SIZE; i++)
	{
		if (!_inventory[i])
		{
			_inventory[i] = m;
			std::cout << _name << " equipped " << m->getType() << " in slot " << i << std::endl;
			return;
		}
	}
	std::cout << _name << "'s inventory is full, cannot equip " << m->getType() << std::endl;
	delete m;
}

void	Character::unequip(int idx)
{
	if (idx >= 0 && idx < INV_SIZE && _inventory[idx])
	{
		AMateria* tmp = _inventory[idx];
		std::cout << _name << " unequipped " << tmp->getType() << " from slot " << idx << std::endl;
		_inventory[idx] = 0;
		if (_floorCount < FLOOR_SIZE)
		{
			_floor[_floorCount++] = tmp;
		}
		else
		{
			std::cout << "Floor is full! Leaking memory for unequipped materia!" << std::endl;
			delete tmp;
		}
	}
	else
		std::cout << _name << " tried to unequip empty/invalid slot " << idx << std::endl;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < INV_SIZE && _inventory[idx])
	{
		std::cout << _name << " uses " << _inventory[idx]->getType() << " on " << target.getName() << ": ";
		_inventory[idx]->use(target);
	}
	else
		std::cout << _name << " tried to use empty/invalid slot " << idx << std::endl;
}
