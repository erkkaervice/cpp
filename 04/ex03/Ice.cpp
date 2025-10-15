/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:40:16 by eala-lah          #+#    #+#             */
/*   Updated: 2025/10/15 13:40:25 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include <iostream>

Ice::Ice() : AMateria("ice")
{
	std::cout << "Ice constructor called" << std::endl;
}

Ice::Ice(const Ice &other) : AMateria(other)
{
	std::cout << "Ice copy constructor called" << std::endl;
}

Ice &Ice::operator=(const Ice &other)
{
	AMateria::operator=(other);
	std::cout << "Ice copy assignment called" << std::endl;
	return *this;
}

Ice::~Ice()
{
	std::cout << "Ice destructor called" << std::endl;
}

AMateria* Ice::clone() const
{
	return new Ice(*this);
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
