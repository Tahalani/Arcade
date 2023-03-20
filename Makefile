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

OBJ	=	$(SRC:.cpp=.o)

all:	core graphicals games
	

core:	$(NAME)
$(NAME): $(OBJ)
	g++ $(CXXFLAGS)	-o $(NAME)	$(OBJ) -ldl -fno-gnu-unique

games:
	make -C src/Game/Snake/
	make -C src/Game/Pacman/
	mv src/Game/Snake/arcade_snake.so lib/
	mv src/Game/Pacman/arcade_pacman.so lib/

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
	make -C src/Game/Snake/ clean
	make -C src/Game/Pacman/ clean

fclean:	clean
	rm -f $(NAME)
	rm -f $(OBJ)
	rm -f lib/*.so
	make -C src/graphics/Ncurse/ fclean
	make -C src/graphics/SDL/ fclean
	make -C src/graphics/SFML/ fclean
	make -C src/Game/Snake/ fclean
	make -C src/Game/Pacman/ fclean

re:	fclean all

.PHONY:	all clean fclean re
