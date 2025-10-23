/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 15:45:14 by eala-lah          #+#    #+#             */
/*   Updated: 2025/10/23 15:45:24 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(void) :
	AForm("RobotomyRequestForm", 72, 45), _target("DefaultTarget")
{
	std::srand(std::time(0));
}

RobotomyRequestForm::RobotomyRequestForm(std::string const& target) :
	AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::srand(std::time(0));
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src) :
	AForm(src), _target(src._target)
{
	std::srand(std::time(0));
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs)
{
	if (this != &rhs)
	{
		AForm::operator=(rhs);
		_target = rhs._target;
	}
	return *this;
}

void	RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
	checkExecution(executor);

	std::cout << "* VRRRRRR... BZZZZZZT... DRILL NOISES *" << std::endl;
	if (std::rand() % 2)
		std::cout << _target << " has been robotomized successfully!" << std::endl;
	else
		std::cout << "Robotomy on " << _target << " failed." << std::endl;
}
