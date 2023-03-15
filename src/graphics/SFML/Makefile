##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

NAME		=	arcade_sfml.so

SRC 		=	SFML.cpp	\

LDFLAGS 	= -lsfml-graphics -lsfml-window -lsfml-system

OBJ	=	$(SRC:.cpp=.o)

all:	$(NAME)
$(NAME): $(OBJ)
	g++ -o $(NAME) -shared -fPIC $(OBJ)

clean:
	rm -f *.gcda *.gcno

fclean:	clean
	rm -f $(OBJ)

re:	fclean all

.PHONY:	all clean fclean re