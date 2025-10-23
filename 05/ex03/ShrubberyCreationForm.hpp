/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 15:43:53 by eala-lah          #+#    #+#             */
/*   Updated: 2025/10/23 15:44:00 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <string>

class	ShrubberyCreationForm : public AForm
{
	private:
		std::string	_target;

	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string const& target);
		ShrubberyCreationForm(const ShrubberyCreationForm& src);
		virtual ~ShrubberyCreationForm();

		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& rhs);

		virtual void	execute(Bureaucrat const& executor) const;
};

#endif
