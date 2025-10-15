/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:30:12 by eala-lah          #+#    #+#             */
/*   Updated: 2025/10/15 13:30:23 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal
{
protected:
	std::string type;

public:
	WrongAnimal();
	virtual ~WrongAnimal();
	void makeSound() const;
	std::string getType() const;
};

#endif
