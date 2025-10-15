/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:39:58 by eala-lah          #+#    #+#             */
/*   Updated: 2025/10/15 13:40:09 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria(std::string const & t) : type(t)
{
	std::cout << "AMateria constructor called" << std::endl;
}

AMateria::AMateria(const AMateria &other)
{
	*this = other;
	std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria &AMateria::operator=(const AMateria &other)
{
	if (this != &other)
		type = other.type;
	std::cout << "AMateria copy assignment called" << std::endl;
	return *this;
}

AMateria::~AMateria()
{
	std::cout << "AMateria destructor called" << std::endl;
}

std::string const & AMateria::getType() const
{
	return type;
}

void AMateria::use(ICharacter &target)
{
	(void)target;
}
