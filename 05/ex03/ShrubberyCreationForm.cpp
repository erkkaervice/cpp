/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 15:44:13 by eala-lah          #+#    #+#             */
/*   Updated: 2025/10/24 15:03:29 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(void) :
	AForm("ShrubberyCreationForm", 145, 137), _target("DefaultTarget") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const& target) :
	AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src) :
	AForm(src), _target(src._target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs)
{
	if (this != &rhs)
	{
		AForm::operator=(rhs);
		_target = rhs._target;
	}
	return *this;
}

void	ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	checkExecution(executor);

	std::ofstream	outFile((_target + "_shrubbery").c_str());
	if (!outFile.is_open())
	{
		std::cerr << "Error: Could not open file " << (_target + "_shrubbery") << std::endl;
		return;
	}

	outFile << "           &&& &&  & &&" << std::endl;
	outFile << "       && &\\/&\\|& ()|/ @, &&" << std::endl;
	outFile << "       &\\/(/&/&||/& /_/)_&/_&" << std::endl;
	outFile << "    &() &\\/&|()|/&\\/ '%\" & ()" << std::endl;
	outFile << "   &_\\_&&_\\ |& |&&/&__%_/_& &&" << std::endl;
	outFile << "&&   && & &| &| /& & % ()& /&&" << std::endl;
	outFile << " ()&_---()&\\&\\|&&-&&--%---()~" << std::endl;
	outFile << "     &&     \\|||" << std::endl;
	outFile << "             |||" << std::endl;
	outFile << "             |||" << std::endl;
	outFile << "             |||" << std::endl;
	outFile << "       , -=-~  .-^- _" << std::endl;
	outFile.close();
}
