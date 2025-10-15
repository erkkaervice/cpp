/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ADog.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:37:51 by eala-lah          #+#    #+#             */
/*   Updated: 2025/10/15 13:37:58 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ADOG_HPP
#define ADOG_HPP

#include "AAnimal.hpp"

class ADog : public AAnimal
{
public:
	ADog();
	ADog(const ADog &other);
	ADog &operator=(const ADog &other);
	~ADog();

	void makeSound() const;
};

#endif
