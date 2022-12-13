# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skhali <skhali@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/12 20:24:07 by skhali            #+#    #+#              #
#    Updated: 2022/12/12 22:11:32 by skhali           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HEADERS			=	Animal.hpp \
					WrongAnimal.hpp \
					Cat.hpp		\
					WrongCat.hpp		\
					Dog.hpp

SRCS			=	main.cpp		\
					Animal.cpp    \
					WrongAnimal.cpp    \
					Dog.cpp    \
					Cat.cpp    \
					WrongCat.cpp    \

OBJS			=	${SRCS:.cpp=.o}

DEPS			=	${SRCS:.cpp=.d}

NAME			=	main

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

-include : ${DEPS}

.PHONY:			all clean fclean