/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 15:25:08 by eala-lah          #+#    #+#             */
/*   Updated: 2025/10/13 14:11:14 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

int	main(void)
{
	Zombie*	babyZombie = NULL;

	if (babyZombie == NULL)
		std::cout << "The cradle of filth is empty." << std::endl;

	std::cout << std::endl;

	std::cout << "--- Demonstrating Heap Allocation ---" << std::endl;
	babyZombie = newZombie("BabyZombie");
	if (babyZombie != NULL)
		std::cout << "BabyZombie was born, the cradle of filth is no longer empty." << std::endl;

	std::cout << std::endl;

	std::cout << "--- Demonstrating Stack Allocation ---" << std::endl;
	randomChump("TeenZombie");

	std::cout << std::endl;

	std::cout << "--- Manually Emptying The Cradle of Filth ---" << std::endl;
	delete babyZombie;
	babyZombie = NULL;

	if (babyZombie == NULL)
		std::cout << "BabyZombie died, so the cradle of filth is empty again." << std::endl;

	std::cout << std::endl;
	std::cout << "--- End of Story ---" << std::endl;
	return 0;
}
