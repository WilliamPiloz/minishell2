##
## EPITECH PROJECT, 2020
## B-PSU-101-MPL-1-1-minishell1-william1.piloz
## File description:
## Makefile
##

CC	=	gcc

CFLAGS	=	-I./include -L./lib -lmy -W -Wall -Wextra

SRC	=	$(wildcard src/minishell1/*.c) \
		$(wildcard src/minishell2/*.c) \
		src/main.c

PRJC	=	mysh

SRCL	=	$(wildcard lib/*.c)

OBJ	=	$(SRCL:.c=.o)

LIB	=	libmy.a

all : $(LIB) $(PRJC)

$(LIB) : $(OBJ)
		ar rsc $(LIB) $(OBJ)
		cp $(LIB) ./lib

$(PRJC) :
		$(CC) -o $(PRJC) $(SRC) $(CFLAGS)

clean :
		rm -rf $(OBJ)

fclean : clean
		rm -rf $(LIB)
		rm -rf ./lib/$(LIB)
		rm -rf $(PRJC)

re : fclean all