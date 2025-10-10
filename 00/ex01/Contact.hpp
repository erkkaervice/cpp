/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 12:50:57 by eala-lah          #+#    #+#             */
/*   Updated: 2025/10/10 14:35:35 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iostream>

class	Contact
{
	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickname;
		std::string	_phoneNumber;
		std::string	_darkestSecret;

	public:
		Contact();
		~Contact();

		void	setFirstName(const std::string& firstName);
		void	setLastName(const std::string& lastName);
		void	setNickname(const std::string& nickname);
		void	setPhoneNumber(const std::string& phoneNumber);
		void	setDarkestSecret(const std::string& darkestSecret);

		const std::string&	getFirstName() const;
		const std::string&	getLastName() const;
		const std::string&	getNickname() const;
		const std::string&	getPhoneNumber() const;
		const std::string&	getDarkestSecret() const;
};

#endif
