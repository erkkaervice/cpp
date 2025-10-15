/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:14:38 by eala-lah          #+#    #+#             */
/*   Updated: 2025/10/15 16:14:52 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	std::cout << "--- BATTLE ARENA ---" << std::endl;
	ClapTrap	clappy("Clappy");
	ScavTrap	scavvy("Scavvy");
	std::cout << std::endl;

	std::cout << "--- ROUND 1 ---" << std::endl;
	clappy.attack("Scavvy");
	scavvy.takeDamage(clappy.getAttackDamage());
	std::cout << "Scavvy has " << scavvy.getHitPoints() << " HP." << std::endl;
	std::cout << std::endl;

	std::cout << "--- ROUND 2 ---" << std::endl;
	scavvy.attack("Clappy");
	clappy.takeDamage(scavvy.getAttackDamage());
	std::cout << "Clappy has " << clappy.getHitPoints() << " HP." << std::endl;
	std::cout << std::endl;

	std::cout << "--- ROUND 3 ---" << std::endl;
	scavvy.beRepaired(10);
	scavvy.guardGate();
	std::cout << "Scavvy has " << scavvy.getHitPoints() << " HP." << std::endl;
	std::cout << std::endl;
	
	std::cout << "--- DESTRUCTION ---" << std::endl;
	return 0;
}
