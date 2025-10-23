/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 15:48:00 by eala-lah          #+#    #+#             */
/*   Updated: 2025/10/23 15:48:04 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include "AForm.hpp"

class	Intern
{
	public:
		Intern(void);
		Intern(const Intern& src);
		~Intern();

		Intern& operator=(const Intern& rhs);

		AForm*	makeForm(std::string const& formName, std::string const& target);
};

#endif
