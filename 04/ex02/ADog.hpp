/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ADog.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:37:51 by eala-lah          #+#    #+#             */
/*   Updated: 2025/10/21 16:58:03 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ADOG_HPP
# define ADOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class	ADog : public AAnimal
{
	private:
		Brain*	brain;

	public:
		ADog(void);
		ADog(const ADog& other);
		ADog& operator=(const ADog& other);
		virtual ~ADog();

		virtual void	makeSound(void) const;
		virtual Brain*	getBrain(void) const;
};

#endif
