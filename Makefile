UNAME_S = $(shell uname -s)

ifeq ($(UNAME_S),Linux)
	LIBS = -L./libs/minilibx -lmlx -L/usr/lib -lXext -lX11 -lm -lbsd
	MLX = mlx_lin
	CLEAN = clean_lin

endif
ifeq ($(UNAME_S),Darwin)
	LIBS = -L./libs/minilibx_OSX -lmlx -framework OpenGL -framework AppKit
	MLX = mlx_osx
	CLEAN = clean_osx
endif

LIBS +=		-L./libs/ft_printf -lftprintf -L./libs/get_next_line -lgetnextline -L./libs/libft -lft
SOURCES = 	main.c mlx_helpers.c
OBJECTS =	$(SOURCES:.c=.o)
HEADER = 	so_long.h
CC = 		gcc
NAME =		so_long
FLAGS =		-Wall -Wextra -Werror
VPATH = 	obj:src:hdr

.PHONY:		all re clean fclean

all:		gnl ftprintf libft $(MLX) $(NAME)

gnl:	
			@make -C libs/get_next_line

ftprintf:	
			@make -C libs/ft_printf

libft:	
			@make -C libs/libft

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
			@make clean -C libs/ft_printf
			@make clean -C libs/get_next_line
			@make clean -C libs/libft


clean_lin:
			rm -rf obj/
#			@make clean -C libs/ft_printf
			@make clean -C libs/minilibx

clean_osx:
			rm -rf obj/
#			@make clean -C libs/ft_printf
			@make clean -C libs/minilibx_OSX

fclean:		clean
			rm -rf $(NAME)
			@make fclean -C libs/ft_printf
			@make fclean -C libs/get_next_line
			@make fclean -C libs/libft

re:			fclean all

os:
	@echo $(UNAME_S)
	@echo $(MLX)
	@echo $(LIBS)
	@echo $(CLEAN)

#gcc main.c -L./minilibx -lmlx -L/usr/lib -lXext -lX11 -lm -lbsd -o run
