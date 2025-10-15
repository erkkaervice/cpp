# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/13 12:10:00 by eala-lah          #+#    #+#              #
#    Updated: 2025/10/13 15:07:59 by eala-lah         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= MFCIOCF

SRCS		= main.cpp Fixed.cpp
OBJS		= $(SRCS:.cpp=.o)

CXX		= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp Fixed.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
