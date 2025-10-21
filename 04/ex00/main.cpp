/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:27:15 by eala-lah          #+#    #+#             */
/*   Updated: 2025/10/21 16:32:40 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int	main(void)
{
	const Animal*	meta = new Animal();
	const Animal*	j = new Dog();
	const Animal*	i = new Cat();

	std::cout << std::endl;
	std::cout << "j is type: " << j->getType() << " " << std::endl;
	std::cout << "i is type: " << i->getType() << " " << std::endl;
	std::cout << std::endl;

	std::cout << "Calling makeSound() via Animal pointers:" << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	std::cout << std::endl;

	std::cout << "Deleting Animals:" << std::endl;
	delete meta;
	delete j;
	delete i;
	std::cout << std::endl;

	std::cout << "--- WRONG VERSION ---" << std::endl;
	const WrongAnimal*	wmeta = new WrongAnimal();
	const WrongAnimal*	wcat = new WrongCat();
	std::cout << std::endl;

	std::cout << "wcat is type: " << wcat->getType() << " " << std::endl;
	std::cout << std::endl;

	std::cout << "Calling makeSound() via WrongAnimal pointers:" << std::endl;
	wcat->makeSound();
	wmeta->makeSound();
	std::cout << std::endl;

	std::cout << "Deleting WrongAnimals:" << std::endl;
	delete wmeta;
	delete wcat;

	return 0;
}
