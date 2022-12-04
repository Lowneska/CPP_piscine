# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skhali <skhali@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/03 18:50:32 by skhali            #+#    #+#              #
#    Updated: 2022/12/03 18:55:11 by skhali           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HEADERS			=	Zombie.hpp

SRCS			=	main.cpp		\
					zombieHorde.cpp  \
					Zombie.cpp

OBJS			=	${SRCS:.cpp=.o}

NAME			=	zombie

CC				=	c++
RM				=	rm -rf
CFLAGS			=	-Wall -Wextra -Werror -std=c++98

### Commandes

all:			${NAME}

${NAME}:		${OBJS}
				${CC} ${CFLAGS} ${OBJS} -o ${NAME}

.cpp.o:
				${CC} -c ${CFLAGS} $^ -o $@

clean:
				${RM} ${OBJS} 

fclean:			clean
				${RM} ${NAME}

re:				fclean all

.PHONY:			all clean fclean