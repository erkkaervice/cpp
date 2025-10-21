/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ACat.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:38:50 by eala-lah          #+#    #+#             */
/*   Updated: 2025/10/21 16:58:15 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACAT_HPP
# define ACAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class	ACat : public AAnimal
{
	private:
		Brain*	brain;

	public:
		ACat(void);
		ACat(const ACat& other);
		ACat& operator=(const ACat& other);
		virtual ~ACat();

		virtual void	makeSound(void) const;
		virtual Brain*	getBrain(void) const;
};

#endif
