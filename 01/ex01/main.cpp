/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 15:35:04 by eala-lah          #+#    #+#             */
/*   Updated: 2025/10/13 14:11:14 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name);

int	main(void)
{
	int const	hordeSize = 5;
	Zombie*		horde;

	std::cout << "--- Calling for a horde of " << hordeSize << " zombies ---" << std::endl;
	horde = zombieHorde(hordeSize, "Zombie");
	if (!horde)
	{
		std::cout << "Failed to create horde." << std::endl;
		return 1;
	}

	std::cout << "\n--- The horde announces itself ---" << std::endl;
	for (int i = 0; i < hordeSize; i++)
		horde[i].announce();

	std::cout << "\n--- The horde faces Chuck Norris ---" << std::endl;
	delete[] horde;

	std::cout << "\n--- End of Story ---" << std::endl;
	return 0;
}
