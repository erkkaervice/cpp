/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:33:37 by eala-lah          #+#    #+#             */
/*   Updated: 2025/10/21 16:36:12 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>

int	main(void)
{
	const int	numAnimals = 4;
	Animal*		animals[numAnimals];

	std::cout << "--- CREATING ANIMALS ---" << std::endl;
	for (int i = 0; i < numAnimals / 2; ++i)
		animals[i] = new Dog();
	for (int i = numAnimals / 2; i < numAnimals; ++i)
		animals[i] = new Cat();
	std::cout << std::endl;

	std::cout << "--- TESTING BRAINS (Example Idea) ---" << std::endl;
	animals[0]->getBrain()->setIdea(0, "Chase tail");
	std::cout << "Dog 0 Idea 0: " << animals[0]->getBrain()->getIdea(0) << std::endl;
	animals[3]->getBrain()->setIdea(0, "Nap time");
	std::cout << "Cat 3 Idea 0: " << animals[3]->getBrain()->getIdea(0) << std::endl;
	std::cout << std::endl;

	std::cout << "--- TESTING DEEP COPY ---" << std::endl;
	Dog		basicDog;
	basicDog.getBrain()->setIdea(0, "Eat");
	Dog		tmpDog = basicDog;

	std::cout << "Original Dog Idea 0: " << basicDog.getBrain()->getIdea(0) << std::endl;
	std::cout << "Copied Dog Idea 0:   " << tmpDog.getBrain()->getIdea(0) << std::endl;
	tmpDog.getBrain()->setIdea(0, "Sleep");
	std::cout << "Original Dog Idea 0 (after copy modified): " << basicDog.getBrain()->getIdea(0) << std::endl;
	std::cout << "Copied Dog Idea 0 (after modification):   " << tmpDog.getBrain()->getIdea(0) << std::endl;
	std::cout << std::endl;

	std::cout << "--- DELETING ANIMALS ---" << std::endl;
	for (int i = 0; i < numAnimals; ++i)
		delete animals[i];
	std::cout << std::endl;

	std::cout << "--- BASIC DOG DESTRUCTION ---" << std::endl;

	return 0;
}
