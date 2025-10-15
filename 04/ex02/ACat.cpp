/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ACat.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:38:19 by eala-lah          #+#    #+#             */
/*   Updated: 2025/10/15 13:39:22 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ACat.hpp"

ACat::ACat()
{
	type = "Cat";
	std::cout << "ACat constructor called" << std::endl;
}

ACat::ACat(const ACat &other) : AAnimal(other)
{
	std::cout << "ACat copy constructor called" << std::endl;
}

ACat &ACat::operator=(const ACat &other)
{
	if (this != &other)
		AAnimal::operator=(other);
	std::cout << "ACat copy assignment operator called" << std::endl;
	return *this;
}

ACat::~ACat()
{
	std::cout << "ACat destructor called" << std::endl;
}

void ACat::makeSound() const
{
	std::cout << "Meow!" << std::endl;
}
