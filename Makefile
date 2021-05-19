##
## EPITECH PROJECT, 2021
## makefile
## File description:
## desc
##

SRCS	=	main.c							            \
			src/cd/handle_cd.c				            \
			src/cd/replace_home.c                       \
			src/minishell1.c				            \
			src/init.c				            		\
			src/redirection/stdout_redirection.c		\
			src/redirection/stdin_redirection.c			\
			src/separator.c				                \
			src/commands/cd.c				            \
			src/commands/exit.c				            \
			src/commands/env/env.c			            \
			src/commands/env/unsetenv.c		            \
			src/commands/env/setenv.c		            \
			src/commands/executables/built_in.c		    \
			src/commands/executables/fork_processes.c   \

all:
	cd lib/my/ && make all
	gcc -g -o mysh $(SRCS) -I./include -L./lib/my/ -lmy

clean:
		rm -f *.o
		rm -f *~

fclean:	clean

		rm lib/libmy.a
		cd lib/my/ && make fclean

re:		fclean all