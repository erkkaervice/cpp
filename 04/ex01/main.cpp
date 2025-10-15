/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:33:37 by eala-lah          #+#    #+#             */
/*   Updated: 2025/10/15 13:34:23 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
	Dog dog1;
	Cat cat1;

	Brain *dogBrain = new Brain();
	dogBrain->setIdea(0, "Chase the cat");
	dog1.setBrain(dogBrain);

	Brain *catBrain = new Brain();
	catBrain->setIdea(0, "Sleep");
	cat1.setBrain(catBrain);

	std::cout << "Dog's idea 0: " << dog1.getBrain()->getIdea(0) << std::endl;
	std::cout << "Cat's idea 0: " << cat1.getBrain()->getIdea(0) << std::endl;

	delete dogBrain;
	delete catBrain;

	return 0;
}
