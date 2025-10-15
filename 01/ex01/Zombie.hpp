/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 15:35:16 by eala-lah          #+#    #+#             */
/*   Updated: 2025/10/13 14:11:14 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class	Zombie
{
	private:
		std::string	_name;

	public:
		Zombie(void);
		~Zombie(void);

		void	announce(void);
		void	setName(std::string name);
};

#endif
