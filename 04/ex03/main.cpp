/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:42:04 by eala-lah          #+#    #+#             */
/*   Updated: 2025/10/22 13:37:48 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>

int	main(void)
{
	IMateriaSource*	src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	std::cout << std::endl;

	ICharacter*	me = new Character("me");
	AMateria*	tmp = 0;

	std::cout << std::endl;

	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("fire");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);

	std::cout << std::endl;

	ICharacter*	bob = new Character("bob");

	std::cout << std::endl;

	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);
	me->use(4, *bob);

	std::cout << std::endl;

	std::cout << "--- TESTING FLOOR LIMIT ---" << std::endl;
	Character*	litterBug = new Character("LitterBug");
	for (int i = 0; i < INV_SIZE; ++i)
	{
		tmp = src->createMateria(((i % 2) == 0) ? "ice" : "cure");
		litterBug->equip(tmp);
	}
	for (int i = 0; i < FLOOR_SIZE + 5; ++i)
	{
		if (i < INV_SIZE)
			litterBug->unequip(i);
		else
		{
			tmp = src->createMateria("ice");
			litterBug->equip(tmp);
			litterBug->unequip(0);
		}
	}
	std::cout << "--- FINISHED FLOOR TEST ---" << std::endl;
	std::cout << std::endl;


	std::cout << "--- TESTING UNEQUIP/USE ON 'me' ---" << std::endl;
	me->unequip(0);
	me->use(0, *bob);

	std::cout << std::endl;

	std::cout << "--- TESTING COPY ---" << std::endl;
	Character*	charles = new Character("Charles");
	tmp = src->createMateria("ice");
	charles->equip(tmp);
	Character*	charles_copy = new Character(*charles);
	charles_copy->use(0, *bob);

	std::cout << std::endl;

	std::cout << "--- DESTRUCTION ---" << std::endl;
	delete bob;
	delete me;
	delete src;
	delete charles;
	delete charles_copy;
	delete litterBug;

	return 0;
}
