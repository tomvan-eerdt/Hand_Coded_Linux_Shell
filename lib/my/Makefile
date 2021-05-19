##
## EPITECH PROJECT, 2020
## makefile
## File description:
## desc
##

CC	= gcc

ARRC	= ar rc

RM	= rm -f

RANLIB  = ranlib

NAME	= libmy.a

CFLAGS	= -I ./include

SRCS	=	utils/char_to_int.c				\
			utils/compare_strings.c			\
			utils/my_strlen.c				\
			utils/my_strcat.c			    \
			utils/my_putstr.c			    \
			utils/get_home.c			    \
			utils/my_put_nbr.c				\
			utils/create_node.c				\
			utils/copy_part_str.c			\
			utils/my_putchar.c				\
			utils/get_file_count.c			\
			utils/check_str_contains.c	    \
			utils/remove_spaces_beg.c	    \
			utils/compare_part_str.c	    \
			utils/my_strpy.c                \
			utils/my_power.c                \
			utils/my_getnbr.c               \
			utils/exec_path.c               \

OBJS	= $(SRCS:.c=.o)

all: $(NAME) clean

$(NAME): $(OBJS)
	$(ARRC) $(NAME) $(OBJS)
	$(RANLIB) $(NAME)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re: fclean all
