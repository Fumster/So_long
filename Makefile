OSFLAG 				:=
	UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S),Linux)
		OSFLAG += LINUX
	endif
	ifeq ($(UNAME_S),Darwin)
		OSFLAG += OSX
	endif


SOURCES = 	main.c mlx_helpers.c
OBJECTS =	$(SOURCES:.c=.o)
HEADER = 	so_long.h
CC = 		gcc
NAME =		so_long
INCLUDES =	-L./libs/ft_printf -lftprintf -L./libs/minilibx -lmlx -L/usr/lib -lXext -lX11 -lm -lbsd
FLAGS =		-Wall -Wextra -Werror
VPATH = 	obj:src:hdr

.PHONY:		all re clean fclean

all:		ftprintf mlx $(NAME)

ftprintf:	
			@make -C libs/ft_printf

mlx:
			@make -C libs/minilibx

$(NAME):	$(OBJECTS)
			$(CC) $(FLAGS) $(addprefix obj/,$(OBJECTS)) $(INCLUDES) -o $@

%.o:		%.c $(HEADER)
			@mkdir -p obj
			$(CC) $(FLAGS) $< -c -o obj/$@

clean:
			rm -rf obj/
			@make clean -C libs/ft_printf
			@make clean -C libs/minilibx

fclean:		clean
			rm -rf $(NAME)
			@make fclean -C libs/ft_printf

re:			fclean all

os:
	@echo $(OSFLAG)


#gcc main.c -L./minilibx -lmlx -L/usr/lib -lXext -lX11 -lm -lbsd -o run
