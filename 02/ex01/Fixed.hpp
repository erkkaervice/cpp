/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 15:29:32 by eala-lah          #+#    #+#             */
/*   Updated: 2025/10/20 15:57:31 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class	Fixed
{
	private:
		int			_value;
		static const int	_fractionalBits;

	public:
		Fixed(void);
		Fixed(int n);
		Fixed(float f);
		Fixed(const Fixed& other);
		~Fixed(void);

		Fixed&	operator=(const Fixed& other);

		int	getRawBits(void) const;
		void	setRawBits(int raw);

		float	toFloat(void) const;
		int	toInt(void) const;
};

std::ostream&	operator<<(std::ostream& out, const Fixed& f);

#endif
