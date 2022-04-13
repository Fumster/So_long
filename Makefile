SOURCES = 	main.c
OBJECTS =	$(SOURCES:.c=.o)
HEADER = 	so_long.h
CC = 		gcc
NAME =		so_long
INCLUDES =	-L./minilibx -lmlx -L/usr/lib -lXext -lX11 -lm -lbsd
FLAGS =		-Wall -Wextra -Werror

.PHONY:		all re clean fclean

all:		$(NAME)

$(NAME):	obj/$(OBJECTS)
			$(CC) $(FLAGS) obj/$(OBJECTS) $(INCLUDES) -o $@

obj/%.o:		src/%.c hdr/$(HEADER)
			$(CC) $(FLAGS) $< -c -o $@

clean:
			rm -rf obj/$(OBJECTS)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all



#gcc main.c -L./minilibx -lmlx -L/usr/lib -lXext -lX11 -lm -lbsd -o run
