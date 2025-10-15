/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ADog.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:38:05 by eala-lah          #+#    #+#             */
/*   Updated: 2025/10/15 13:39:22 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ADog.hpp"

ADog::ADog()
{
	type = "Dog";
	std::cout << "ADog constructor called" << std::endl;
}

ADog::ADog(const ADog &other) : AAnimal(other)
{
	std::cout << "ADog copy constructor called" << std::endl;
}

ADog &ADog::operator=(const ADog &other)
{
	if (this != &other)
		AAnimal::operator=(other);
	std::cout << "ADog copy assignment operator called" << std::endl;
	return *this;
}

ADog::~ADog()
{
	std::cout << "ADog destructor called" << std::endl;
}

void ADog::makeSound() const
{
	std::cout << "Woof!" << std::endl;
}
