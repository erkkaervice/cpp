/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 12:51:11 by eala-lah          #+#    #+#             */
/*   Updated: 2025/10/10 14:35:35 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {}
Contact::~Contact() {}

void	Contact::setFirstName(const std::string& firstName)		{ this->_firstName = firstName; }
void	Contact::setLastName(const std::string& lastName)		{ this->_lastName = lastName; }
void	Contact::setNickname(const std::string& nickname)		{ this->_nickname = nickname; }
void	Contact::setPhoneNumber(const std::string& phoneNumber)		{ this->_phoneNumber = phoneNumber; }
void	Contact::setDarkestSecret(const std::string& darkestSecret)	{ this->_darkestSecret = darkestSecret; }

const std::string&	Contact::getFirstName() const		{ return (this->_firstName); }
const std::string&	Contact::getLastName() const		{ return (this->_lastName); }
const std::string&	Contact::getNickname() const		{ return (this->_nickname); }
const std::string&	Contact::getPhoneNumber() const		{ return (this->_phoneNumber); }
const std::string&	Contact::getDarkestSecret() const	{ return (this->_darkestSecret); }
