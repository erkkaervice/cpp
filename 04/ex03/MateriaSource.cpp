/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:41:53 by eala-lah          #+#    #+#             */
/*   Updated: 2025/10/15 13:41:58 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		materias[i] = nullptr;
	std::cout << "MateriaSource constructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	for (int i = 0; i < 4; i++)
		materias[i] = other.materias[i] ? other.materias[i]->clone() : nullptr;
	std::cout << "MateriaSource copy constructor called" << std::endl;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			delete materias[i];
			materias[i] = other.materias[i] ? other.materias[i]->clone() : nullptr;
		}
	}
	std::cout << "MateriaSource copy assignment called" << std::endl;
	return *this;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
		delete materias[i];
	std::cout << "MateriaSource destructor called" << std::endl;
}

void MateriaSource::learnMateria(AMateria* m)
{
	if (!m)
		return;
	for (int i = 0; i < 4; i++)
	{
		if (!materias[i])
		{
			materias[i] = m->clone();
			return;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (materias[i] && materias[i]->getType() == type)
			return materias[i]->clone();
	}
	return nullptr;
}
