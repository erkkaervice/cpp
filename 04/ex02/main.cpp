/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:37:19 by eala-lah          #+#    #+#             */
/*   Updated: 2025/10/15 13:37:33 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ADog.hpp"
#include "ACat.hpp"

int main()
{
	const AAnimal* animals[4];
	for (int i = 0; i < 2; i++)
		animals[i] = new ADog();
	for (int i = 2; i < 4; i++)
		animals[i] = new ACat();

	for (int i = 0; i < 4; i++)
	{
		std::cout << animals[i]->getType() << " makes ";
		animals[i]->makeSound();
	}

	for (int i = 0; i < 4; i++)
		delete animals[i];

	return 0;
}
