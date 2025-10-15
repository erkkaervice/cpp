/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 16:19:21 by eala-lah          #+#    #+#             */
/*   Updated: 2025/10/15 16:21:41 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	std::cout << "--- CLAPTRAP TEST ---" << std::endl;
	ClapTrap	clappy("Clappy");
	clappy.attack("a training dummy");
	std::cout << std::endl;

	std::cout << "--- SCAVTRAP TEST ---" << std::endl;
	ScavTrap	scavvy("Scavvy");
	scavvy.attack("another training dummy");
	scavvy.guardGate();
	std::cout << std::endl;

	std::cout << "--- FRAGTRAP TEST ---" << std::endl;
	FragTrap	fraggy("Fraggy");
	std::cout << "Fraggy has " << fraggy.getHitPoints() << " HP, "
			  << fraggy.getEnergyPoints() << " EP, and "
			  << fraggy.getAttackDamage() << " Attack Damage." << std::endl;
	fraggy.attack("the final training dummy");
	fraggy.highFivesGuys();
	std::cout << std::endl;

	std::cout << "--- DESTRUCTION SEQUENCE ---" << std::endl;
	return 0;
}
