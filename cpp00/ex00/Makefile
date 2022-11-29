NAME = megaphone

CPPFLAGS = -Werror -Wall -Wextra

CC = clang++

all: $(NAME)

$(NAME): megaphone.cpp
	$(CC) $(CPPFLAGS) megaphone.cpp -o $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
.PHONY: all clean fclean re