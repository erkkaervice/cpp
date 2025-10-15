# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/15 13:33:49 by eala-lah          #+#    #+#              #
#    Updated: 2025/10/15 13:34:23 by eala-lah         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= ex01

CXX		= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

SRCS		= main.cpp Brain.cpp
OBJS		= $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
