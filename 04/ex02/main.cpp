/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:37:19 by eala-lah          #+#    #+#             */
/*   Updated: 2025/10/21 17:57:57 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "ADog.hpp"
#include "ACat.hpp"
#include <iostream>

int	main(void)
{
	const int	numAnimals = 4;
	AAnimal*	animals[numAnimals];

	std::cout << "--- Creating Animals ---" << std::endl;
	for (int i = 0; i < numAnimals / 2; ++i)
		animals[i] = new ADog();
	for (int i = numAnimals / 2; i < numAnimals; ++i)
		animals[i] = new ACat();
	std::cout << std::endl;

	std::cout << "--- Testing Sounds ---" << std::endl;
	for (int i = 0; i < numAnimals; ++i)
	{
		std::cout << animals[i]->getType() << " makes sound: ";
		animals[i]->makeSound();
	}
	std::cout << std::endl;

	std::cout << "--- Testing Brains (Example) ---" << std::endl;
	AAnimal*	testDog = animals[0];
	if (testDog && testDog->getBrain())
	{
		testDog->getBrain()->setIdea(0, "Chase Squirrel");
		std::cout << testDog->getType() << " Idea 0: " << testDog->getBrain()->getIdea(0) << std::endl;
	}
	std::cout << std::endl;

	std::cout << "--- Attempting to create AAnimal (should fail compilation) ---" << std::endl;
	// AAnimal	nope; // This line should cause a compile error
	// AAnimal*	fail = new AAnimal(); // This line should also cause a compile error

	std::cout << "--- Deleting Animals ---" << std::endl;
	for (int i = 0; i < numAnimals; ++i)
		delete animals[i];

	return 0;
}
