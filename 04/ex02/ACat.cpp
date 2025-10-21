/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ACat.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:38:19 by eala-lah          #+#    #+#             */
/*   Updated: 2025/10/21 16:58:20 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ACat.hpp"

ACat::ACat(void) : AAnimal()
{
	type = "Cat";
	brain = new Brain();
	std::cout << "ACat: Default constructor called" << std::endl;
}

ACat::ACat(const ACat& other) : AAnimal(other)
{
	std::cout << "ACat: Copy constructor called" << std::endl;
	brain = new Brain(*other.brain);
}

ACat& ACat::operator=(const ACat& other)
{
	std::cout << "ACat: Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		AAnimal::operator=(other);
		delete brain;
		brain = new Brain(*other.brain);
	}
	return *this;
}

ACat::~ACat()
{
	delete brain;
	std::cout << "ACat: Destructor called" << std::endl;
}

void	ACat::makeSound(void) const
{
	std::cout << "ACat: Meow!" << std::endl;
}

Brain*	ACat::getBrain(void) const
{
	return brain;
}
