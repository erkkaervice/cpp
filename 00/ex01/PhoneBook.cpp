/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 12:51:44 by eala-lah          #+#    #+#             */
/*   Updated: 2025/10/13 12:21:52 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _currentIndex(0), _contactCount(0) {}
PhoneBook::~PhoneBook() {}

static std::string	getValidInput(const std::string& prompt)
{
	std::string	input;

	while (true)
	{
		std::cout << prompt;
		std::getline(std::cin, input);

		if (std::cin.eof())
			return ("");
		if (!input.empty())
			return (input);
			
		std::cout << "Field cannot be empty. Please try again." << std::endl;
	}
}

void	PhoneBook::addContact()
{
	Contact		newContact;
	std::string	input;

	input = getValidInput("Enter first name: ");
	if (input.empty())
		return;
	newContact.setFirstName(input);

	input = getValidInput("Enter last name: ");
	if (input.empty())
		return;
	newContact.setLastName(input);

	input = getValidInput("Enter nickname: ");
	if (input.empty())
		return;
	newContact.setNickname(input);

	input = getValidInput("Enter phone number: ");
	if (input.empty())
		return;
	newContact.setPhoneNumber(input);

	input = getValidInput("Enter darkest secret: ");
	if (input.empty())
		return;
	newContact.setDarkestSecret(input);

	_contacts[_currentIndex] = newContact;
	_currentIndex = (_currentIndex + 1) % 8;
	if (_contactCount < 8)
		_contactCount++;

	std::cout << "Contact added successfully!" << std::endl;
}

std::string	PhoneBook::_truncate(const std::string& str) const
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");

	return (str);
}

void	PhoneBook::_displayContact(int index) const
{
	if (index < 0 || index >= _contactCount)
	{
		std::cout << "Invalid index." << std::endl;
		return;
	}

	std::cout << "First Name:     " << _contacts[index].getFirstName() << std::endl;
	std::cout << "Last Name:      " << _contacts[index].getLastName() << std::endl;
	std::cout << "Nickname:       " << _contacts[index].getNickname() << std::endl;
	std::cout << "Phone Number:   " << _contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << _contacts[index].getDarkestSecret() << std::endl;
}

void	PhoneBook::searchContacts() const
{
	if (_contactCount == 0)
	{
		std::cout << "PhoneBook is empty." << std::endl;
		return;
	}

	std::cout << std::right << std::setw(10) << "Index" << "|";
	std::cout << std::right << std::setw(10) << "First Name" << "|";
	std::cout << std::right << std::setw(10) << "Last Name" << "|";
	std::cout << std::right << std::setw(10) << "Nickname" << std::endl;

	for (int i = 0; i < _contactCount; ++i)
	{
		std::cout << std::right << std::setw(10) << i << "|";
		std::cout << std::right << std::setw(10) << _truncate(_contacts[i].getFirstName()) << "|";
		std::cout << std::right << std::setw(10) << _truncate(_contacts[i].getLastName()) << "|";
		std::cout << std::right << std::setw(10) << _truncate(_contacts[i].getNickname()) << std::endl;
	}

	std::cout << "Enter the index of the contact to display: ";
	std::string	input;

	std::getline(std::cin, input);
	
	if (std::cin.eof())
		return;

	if (input.length() == 1 && std::isdigit(input[0]))
	{
		int	index = input[0] - '0';

		_displayContact(index);
	}
	else
		std::cout << "Invalid index." << std::endl;
}
