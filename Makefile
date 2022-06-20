UNAME_S = $(shell uname -s)

ifeq ($(UNAME_S),Linux)
	INCLUDES = -L./libs/minilibx -lmlx -L/usr/lib -lXext -lX11 -lm -lbsd
	MLX = mlx_lin
	LIB_MLX = ./libs/minilibx/libmlx.a
	CLEAN = clean_lin

endif
ifeq ($(UNAME_S),Darwin)
	INCLUDES = -L./libs/minilibx_OSX -lmlx -framework OpenGL -framework AppKit
	MLX = mlx_osx
	LIB_MLX = ./libs/minilibx_OSX/libmlx.a
	CLEAN = clean_osx
endif

INCLUDES +=		-L./libs/ft_printf -lftprintf -L./libs/get_next_line -lgetnextline
LIB_PRINTF =	./libs/ft_printf/libftprintf.a
LIB_GNL =	./libs/get_next_line/libgetnextline.a
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
BONUS =		so_long_b
FLAGS =		-Wall -Wextra -Werror
VPATH = 	obj:src:hdr

.PHONY:		all re clean fclean libs

all:		libs $(NAME)

libs:		$(MLX)
			@make -C libs/get_next_line
			@make -C libs/ft_printf

$(LIB_GNL):	
			@make -C libs/get_next_line

$(LIB_PRINTF):	
			@make -C libs/ft_printf

$(LIB_MLX): $(MLX)

mlx_lin:
			@make -C libs/minilibx

mlx_osx:
			@make -C libs/minilibx_OSX

$(NAME):	$(OBJECTS) $(LIB_PRINTF) $(LIB_GNL) $(LIB_MLX)
			$(CC) $(FLAGS) $(addprefix obj/,$(OBJECTS)) $(INCLUDES) -o $@

bonus:		libs $(BONUS)
	
$(BONUS):	$(OBJECTS_B) $(LIB_PRINTF) $(LIB_GNL) $(LIB_MLX)
			$(CC) $(FLAGS) $(addprefix obj/,$(OBJECTS_B)) $(INCLUDES) -o so_long_b

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
			rm -rf $(BONUS)
			@make fclean -C libs/ft_printf
			@make fclean -C libs/get_next_line

re:			fclean all

os:
			@echo $(UNAME_S)
			@echo $(MLX)
			@echo $(INCLUDES)
			@echo $(CLEAN)


#gcc main.c -L./minilibx -lmlx -L/usr/lib -lXext -lX11 -lm -lbsd -o run
