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

LIBS +=		-L./libs/ft_printf -lftprintf -L./libs/get_next_line -lgetnextline
SOURCES = 	main.c map_drawer.c mlx_helpers.c map_helpers.c main_helpers.c \
			destroyer.c map_validator.c player_mover.c
SOURCES_B = 	main_b.c map_drawer_b.c mlx_helpers_b.c map_helpers.c \
				main_helpers_b.c destroyer.c map_validator_b.c player_mover_b.c \
				enemy_mover.c ft_itoa.c
OBJECTS =	$(SOURCES:.c=.o)
OBJECTS_B =	$(SOURCES_B:.c=.o)
HEADER = 	so_long.h
CC = 		gcc
NAME =		so_long
FLAGS =		-Wall -Wextra -Werror
VPATH = 	obj:src:hdr

.PHONY:		all re clean fclean

all:		$(NAME)

gnl:	
			@make -C libs/get_next_line

ftprintf:	
			@make -C libs/ft_printf

mlx_lin:
			@make -C libs/minilibx

mlx_osx:
			@make -C libs/minilibx_OSX

$(NAME):	gnl ftprintf $(MLX) $(OBJECTS)
			$(CC) $(FLAGS) $(addprefix obj/,$(OBJECTS)) $(LIBS) -o $@

bonus:		gnl ftprintf $(MLX) $(OBJECTS_B)
			$(CC) $(FLAGS) $(addprefix obj/,$(OBJECTS_B)) $(LIBS) -o $(NAME)

%.o:		%.c $(HEADER)
			@mkdir -p obj
			$(CC) $(FLAGS) $< -c -o obj/$@

clean:		$(CLEAN)
			@make clean -C libs/ft_printf
			@make clean -C libs/get_next_line


clean_lin:
			rm -rf obj/
			@make clean -C libs/minilibx

clean_osx:
			rm -rf obj/
			@make clean -C libs/minilibx_OSX

fclean:		clean
			rm -rf $(NAME)
			@make fclean -C libs/ft_printf
			@make fclean -C libs/get_next_line

re:			fclean all

os:
			@echo $(UNAME_S)
			@echo $(MLX)
			@echo $(LIBS)
			@echo $(CLEAN)


#gcc main.c -L./minilibx -lmlx -L/usr/lib -lXext -lX11 -lm -lbsd -o run
