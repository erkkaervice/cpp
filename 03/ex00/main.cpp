/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:14:38 by eala-lah          #+#    #+#             */
/*   Updated: 2025/10/15 15:40:29 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	clappy("Clappy");
	ClapTrap	trappy("Trappy");

	std::cout << "\n--- Initial Status ---" << std::endl;
	std::cout << "Clappy: " << clappy.getHitPoints() << " HP, " << clappy.getEnergyPoints() << " EP" << std::endl;
	std::cout << "Trappy: " << trappy.getHitPoints() << " HP, " << trappy.getEnergyPoints() << " EP" << std::endl;

	std::cout << "\n--- Round 1 ---" << std::endl;
	clappy.attack("Trappy");
	trappy.takeDamage(0);
	trappy.beRepaired(5);

	std::cout << "\n--- Status after Round 1 ---" << std::endl;
	std::cout << "Clappy: " << clappy.getHitPoints() << " HP, " << clappy.getEnergyPoints() << " EP" << std::endl;
	std::cout << "Trappy: " << trappy.getHitPoints() << " HP, " << trappy.getEnergyPoints() << " EP" << std::endl;

	std::cout << "\n--- Energy Depletion Test ---" << std::endl;
	ClapTrap	energetic("Energetic");
	for (int i = 0; i < 11; i++)
	{
		energetic.attack("a wall");
		if (i < 10)
			std::cout << "  (Energetic has " << energetic.getEnergyPoints() << " EP left)" << std::endl;
	}

	std::cout << "\n--- Hit Point Depletion Test ---" << std::endl;
	ClapTrap	doomed("Doomed");
	std::cout << "Doomed starts with " << doomed.getHitPoints() << " HP." << std::endl;
	doomed.takeDamage(10);
	std::cout << "Doomed now has " << doomed.getHitPoints() << " HP." << std::endl;
	doomed.attack("the air");

	std::cout << "\n--- OCF Test ---" << std::endl;
	ClapTrap	original("Original");
	ClapTrap	copy(original);
	std::cout << "Copy has " << copy.getHitPoints() << " HP, " << copy.getEnergyPoints() << " EP" << std::endl;
	
	std::cout << "\n--- Destruction begins ---" << std::endl;
	return 0;
}
