##
## EPITECH PROJECT, 2023
## arcade
## File description:
## Makefile
##

NAME		=	arcade

SRC 		=	main.cpp	\
				src/core/arcade.cpp	\

CXXFLAGS	= -g -Wall -Wextra -I./include/

LDFLAGS 	= -lsfml-graphics -lsfml-window -lsfml-system

OBJ	=	$(SRC:.cpp=.o)

all:	core graphicals
	

core:	$(NAME)
$(NAME): $(OBJ)
	g++ $(CXXFLAGS)	-o $(NAME)	$(OBJ) -ldl

graphicals:
	make -C src/graphics/Ncurse/
	make -C src/graphics/SDL/
	make -C src/graphics/SFML/
	mv src/graphics/Ncurse/arcade_ncurses.so lib/
	mv src/graphics/SDL/arcade_sdl2.so lib/
	mv src/graphics/SFML/arcade_sfml.so lib/

clean:
	rm -f *.gcda *.gcno
	make -C src/graphics/Ncurse/ clean
	make -C src/graphics/SDL/ clean
	make -C src/graphics/SFML/ clean

fclean:	clean
	rm -f $(NAME)
	rm -f $(OBJ)
	rm -f lib/*.so
	make -C src/graphics/Ncurse/ fclean
	make -C src/graphics/SDL/ fclean
	make -C src/graphics/SFML/ fclean

re:	fclean all

.PHONY:	all clean fclean re
