/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:40:08 by eala-lah          #+#    #+#             */
/*   Updated: 2025/10/15 13:40:11 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria
{
public:
	Ice();
	Ice(const Ice &other);
	Ice &operator=(const Ice &other);
	~Ice();

	AMateria* clone() const;
	void use(ICharacter &target);
};

#endif
