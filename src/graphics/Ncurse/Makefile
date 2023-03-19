##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

NAME		=	arcade_ncurses.so

SRC 		=	ncurse.cpp	\

LDFLAGS 	= -lncurses

CXXFLAGS 	= -Wall -Wextra -fPIC

OBJ	=	$(SRC:.cpp=.o)

all:	$(NAME)
$(NAME): $(OBJ)
	g++ -o $(NAME) -shared -fPIC $(OBJ) $(LDFLAGS)

clean:
	rm -f *.gcda *.gcno

fclean:	clean
	rm -f $(OBJ)
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
