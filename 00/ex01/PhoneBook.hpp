/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 12:51:30 by eala-lah          #+#    #+#             */
/*   Updated: 2025/10/13 12:26:41 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <string>
# include "Contact.hpp"

class	PhoneBook
{
	private:
		Contact		_contacts[8];
		int		_currentIndex;
		int		_contactCount;

		std::string	_truncate(const std::string& str) const;
		void		_displayContact(int index) const;

	public:
		PhoneBook();
		~PhoneBook();

		void		addContact();
		void		searchContacts() const;
};

#endif
