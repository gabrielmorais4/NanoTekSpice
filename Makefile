##
## EPITECH PROJECT, 2021
## makefile
## File description:
## makefile
##

NAME = nanotekspice

SRC = *.cpp

FLAGS = -std=c++20 -Wall -Wextra -g3

all:
	g++ -o $(NAME) $(SRC) $(FLAGS)

clean:
	rm -f *~ | rm -f *.o

fclean: clean
	rm -f $(NAME)

re:	fclean all