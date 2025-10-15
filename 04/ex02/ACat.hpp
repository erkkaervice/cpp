/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ACat.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:38:50 by eala-lah          #+#    #+#             */
/*   Updated: 2025/10/15 13:39:22 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACat_HPP
#define ACat_HPP

#include "AAnimal.hpp"

class ACat : public AAnimal
{
public:
	ACat();
	ACat(const ACat &other);
	ACat &operator=(const ACat &other);
	~ACat();

	void makeSound() const;
};

#endif
