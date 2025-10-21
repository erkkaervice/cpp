/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:40:56 by eala-lah          #+#    #+#             */
/*   Updated: 2025/10/21 18:47:56 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"
# include <string>

# define INV_SIZE 4
# define FLOOR_SIZE (INV_SIZE * 10)

class	Character : public ICharacter
{
	private:
		std::string	_name;
		AMateria*	_inventory[INV_SIZE];
		AMateria*	_floor[FLOOR_SIZE];
		int		_floorCount;

	public:
		Character(void);
		Character(std::string const& name);
		Character(const Character& other);
		Character& operator=(const Character& other);
		virtual ~Character();

		virtual std::string const&	getName(void) const;
		virtual void			equip(AMateria* m);
		virtual void			unequip(int idx);
		virtual void			use(int idx, ICharacter& target);
};

#endif
