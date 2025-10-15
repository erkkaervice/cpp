# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/15 13:24:53 by eala-lah          #+#    #+#              #
#    Updated: 2025/10/15 16:30:57 by eala-lah         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= DiamondTrap

SRCS		= main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp
OBJS		= $(SRCS:.cpp=.o)

CXX		= c++
CXXFLAGS	= -Wall -Wextra -Werror -std-c++98

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp ClapTrap.hpp ScavTrap.hpp FragTrap.hpp DiamondTrap.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
