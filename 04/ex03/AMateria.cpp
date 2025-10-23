/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:39:58 by eala-lah          #+#    #+#             */
/*   Updated: 2025/10/23 15:18:19 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria(void) : _type("default")
{
	std::cout << "AMateria: Default constructor called" << std::endl;
}

AMateria::AMateria(std::string const& type) : _type(type)
{
	std::cout << "AMateria: Type constructor called" << std::endl;
}

AMateria::AMateria(const AMateria& other)
{
	std::cout << "AMateria: Copy constructor called" << std::endl;
	*this = other;
}

AMateria& AMateria::operator=(const AMateria& other)
{
	std::cout << "AMateria: Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_type = other._type;
	return *this;
}

AMateria::~AMateria()
{
	std::cout << "AMateria: Destructor called" << std::endl;
}

std::string const& AMateria::getType(void) const
{
	return _type;
}

void AMateria::use(ICharacter& target)
{
	std::cout << "AMateria: Base use function called on target " << target.getName() << std::endl;
}
