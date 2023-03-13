##
## EPITECH PROJECT, 2023
## arcade
## File description:
## Makefile
##

NAME	=	arcade

SRC 	=	main.cpp	\

CXXFLAGS	= -g -Wall -Wextra -I./include/

OBJ	=	$(SRC:.cpp=.o)

all:	$(NAME)
$(NAME): $(OBJ)
	g++ $(CXXFLAGS)	-o $(NAME)	$(OBJ)

clean:
	rm -f *.gcda *.gcno

fclean:	clean
	rm -f $(NAME)
	rm -f $(OBJ)

re:	fclean all

.PHONY:	all clean fclean re
