/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ADog.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:38:05 by eala-lah          #+#    #+#             */
/*   Updated: 2025/10/21 16:58:08 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ADog.hpp"

ADog::ADog(void) : AAnimal()
{
	type = "Dog";
	brain = new Brain();
	std::cout << "ADog: Default constructor called" << std::endl;
}

ADog::ADog(const ADog& other) : AAnimal(other)
{
	std::cout << "ADog: Copy constructor called" << std::endl;
	brain = new Brain(*other.brain);
}

ADog& ADog::operator=(const ADog& other)
{
	std::cout << "ADog: Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		AAnimal::operator=(other);
		delete brain;
		brain = new Brain(*other.brain);
	}
	return *this;
}

ADog::~ADog()
{
	delete brain;
	std::cout << "ADog: Destructor called" << std::endl;
}

void	ADog::makeSound(void) const
{
	std::cout << "ADog: Woof!" << std::endl;
}

Brain*	ADog::getBrain(void) const
{
	return brain;
}
