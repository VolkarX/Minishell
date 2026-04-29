#
## EPITECH PROJECT, 2026
## mysh
## File description:
## Makefile mysh
#

CC = clang
CFLAGS = -Wall -Wextra
NAME = mysh

SRC = \
	src/main.c \
	src/components/clearstring.c \
	src/components/finder.c \
	src/components/handler/handle_cd.c \
	src/components/handler/handle_cmd.c \
	src/components/handler/handle_pipe.c \
	src/components/handler/handle_redir_in.c \
	src/components/handler/handle_redir_out.c \
	src/components/handler/handle_sequence.c \
	src/components/handler/handle_exit.c \
	src/components/handler/handle_setenv.c \
	src/components/handler/handle_unsetenv.c \
	src/utils/element/mini_printf.c \
	src/utils/element/my_putchar.c \
	src/utils/element/my_putstr.c \
	src/utils/element/my_strlen.c \
	src/utils/features/env_copy.c \
	src/utils/features/my_getenv.c \
	src/utils/features/pipe.c \
	src/utils/features/parser.c \
	src/utils/features/redir_in.c \
	src/utils/features/redir_out.c \
	src/utils/features/semicolon.c \
	src/utils/functions/is_number.c \
	src/utils/functions/my_atoi.c \
	src/utils/functions/my_strchr.c \
	src/utils/functions/my_strcmp.c \
	src/utils/functions/my_strcpy.c \
	src/utils/functions/my_strcspn.c \
	src/utils/functions/my_strdup.c

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -o $(NAME) $(SRC)

clean:
	rm -f *.o include/*.pch src/*~ src/components/*~ src/utils/*~ *.pch
	rm -f *~ *Zone.Identifier

fclean: clean
	rm -f $(NAME)

re: fclean all

valgrind:
	$(CC) $(CFLAGS) -g3 -o $(NAME) $(SRC)
