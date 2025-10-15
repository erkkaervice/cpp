/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 15:01:56 by eala-lah          #+#    #+#             */
/*   Updated: 2025/10/13 15:39:08 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
private:
	int			_value;

public:
	Fixed();
	Fixed(const Fixed& other);
	Fixed& operator=(const Fixed& other);
	~Fixed();

	int getRawBits() const;
	void setRawBits(int const raw);
};

#endif
