/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:41:41 by eala-lah          #+#    #+#             */
/*   Updated: 2025/10/15 13:41:44 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria* materias[4];

public:
	MateriaSource();
	MateriaSource(const MateriaSource &other);
	MateriaSource &operator=(const MateriaSource &other);
	~MateriaSource();

	void learnMateria(AMateria* m);
	AMateria* createMateria(std::string const & type);
};

#endif
