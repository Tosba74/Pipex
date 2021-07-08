
NAME	= pipex

PATH_S	= ./srcs
PATH_I	= ./includes
PATH_B	= ./bin

SRCS	= main.c
INCLUDE	= pipex.h

FILE	= $(addprefix ${PATH_S}/, &{SRCS})
INC		= $(addprefix ${PATH_I}/, &{INCLUDE})

all:	lib ${NAME}

lib:

${PATH_B}/%o: %.c ${INC}
	clang -Werror -Wall -Wextra -c $< -o $@

${NAME}: 
