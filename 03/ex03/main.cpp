/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:24:44 by eala-lah          #+#    #+#             */
/*   Updated: 2025/10/21 14:15:16 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void)
{
	std::cout << "--- Constructing Diamond ---" << std::endl;
	DiamondTrap	diamond("DI4M-TP");
	std::cout << std::endl;

	std::cout << "--- Checking Stats ---" << std::endl;
	std::cout << "HP: " << diamond.getHitPoints() << std::endl;
	std::cout << "EP: " << diamond.getEnergyPoints() << std::endl;
	std::cout << "AD: " << diamond.getAttackDamage() << std::endl;
	std::cout << std::endl;

	std::cout << "--- Testing Abilities ---" << std::endl;
	diamond.attack("a poor, unsuspecting victim");
	diamond.guardGate();
	diamond.highFivesGuys();
	diamond.whoAmI();
	std::cout << std::endl;

	std::cout << "--- OCF Test ---" << std::endl;
	DiamondTrap	diamond_copy(diamond);
	diamond_copy.whoAmI();
	std::cout << std::endl;

	std::cout << "--- Destruction ---" << std::endl;
	return 0;
}
