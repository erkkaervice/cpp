/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 15:44:57 by eala-lah          #+#    #+#             */
/*   Updated: 2025/10/23 15:45:04 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <string>

class	RobotomyRequestForm : public AForm
{
	private:
		std::string	_target;

	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string const& target);
		RobotomyRequestForm(const RobotomyRequestForm& src);
		virtual ~RobotomyRequestForm();

		RobotomyRequestForm& operator=(const RobotomyRequestForm& rhs);

		virtual void	execute(Bureaucrat const& executor) const;
};

#endif
