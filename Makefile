UNAME_S = $(shell uname -s)

ifeq ($(UNAME_S),Linux)
	LIBS = -L./libs/ft_printf -lftprintf -L./libs/minilibx -lmlx -L/usr/lib -lXext -lX11 -lm -lbsd
	MLX = mlx_lin
	CLEAN = clean_lin

endif
ifeq ($(UNAME_S),Darwin)
	LIBS = -L./libs/ft_printf -lftprintf -L./libs/minilibx_OSX -lmlx -framework OpenGL -framework AppKit
	MLX = mlx_osx
	CLEAN = clean_osx
endif

SOURCES = 	main.c mlx_helpers.c
OBJECTS =	$(SOURCES:.c=.o)
HEADER = 	so_long.h
CC = 		gcc
NAME =		so_long
FLAGS =		-Wall -Wextra -Werror
VPATH = 	obj:src:hdr

.PHONY:		all re clean fclean

all:		ftprintf $(MLX) $(NAME)

ftprintf:	
			@make -C libs/ft_printf

mlx_lin:
			@make -C libs/minilibx

mlx_osx:
			@make -C libs/minilibx_OSX

$(NAME):	$(OBJECTS)
			$(CC) $(FLAGS) $(addprefix obj/,$(OBJECTS)) $(LIBS) -o $@

%.o:		%.c $(HEADER)
			@mkdir -p obj
			$(CC) $(FLAGS) $< -c -o obj/$@

clean:		$(CLEAN)


clean_lin:
			rm -rf obj/
			@make clean -C libs/ft_printf
			@make clean -C libs/minilibx

clean_osx:
			rm -rf obj/
			@make clean -C libs/ft_printf
			@make clean -C libs/minilibx_OSX

fclean:		clean
			rm -rf $(NAME)
			@make fclean -C libs/ft_printf

re:			fclean all

os:
	@echo $(UNAME_S)
	@echo $(MLX)
	@echo $(LIBS)
	@echo $(CLEAN)

#gcc main.c -L./minilibx -lmlx -L/usr/lib -lXext -lX11 -lm -lbsd -o run
