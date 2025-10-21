/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:41:53 by eala-lah          #+#    #+#             */
/*   Updated: 2025/10/21 18:43:52 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource(void) : _count(0)
{
	std::cout << "MateriaSource: Default constructor called" << std::endl;
	for (int i = 0; i < MAX_MATERIAS; i++)
		_learned[i] = 0;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	std::cout << "MateriaSource: Copy constructor called" << std::endl;
	_count = 0;
	for (int i = 0; i < MAX_MATERIAS; i++)
		_learned[i] = 0;
	*this = other;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	std::cout << "MateriaSource: Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < _count; i++)
			delete _learned[i];
		_count = 0;
		for (int i = 0; i < other._count; i++)
		{
			if (other._learned[i])
				learnMateria(other._learned[i]->clone());
		}
		for (int i = _count; i < MAX_MATERIAS; i++)
			_learned[i] = 0;
	}
	return *this;
}


MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource: Destructor called" << std::endl;
	for (int i = 0; i < _count; i++)
		delete _learned[i];
}

void	MateriaSource::learnMateria(AMateria* m)
{
	if (!m)
	{
		std::cout << "MateriaSource cannot learn null Materia." << std::endl;
		return;
	}
	if (_count < MAX_MATERIAS)
	{
		_learned[_count++] = m;
		std::cout << "MateriaSource learned " << m->getType() << std::endl;
	}
	else
	{
		std::cout << "MateriaSource cannot learn more Materias." << std::endl;
		delete m;
	}
}

AMateria*	MateriaSource::createMateria(std::string const& type)
{
	for (int i = 0; i < _count; i++)
	{
		if (_learned[i] && _learned[i]->getType() == type)
		{
			std::cout << "MateriaSource creating " << type << std::endl;
			return _learned[i]->clone();
		}
	}
	std::cout << "MateriaSource does not know type " << type << std::endl;
	return 0;
}
