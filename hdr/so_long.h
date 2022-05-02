#ifndef SO_LONG_H
# define SO_LONG_H

#if defined(__APPLE__) && defined(__MACH__)
	# include "../libs/minilibx_OSX/mlx.h"
	# define ESC_KEY 53
	# define W_KEY 13
	# define S_KEY 1
	# define A_KEY 0
	# define D_KEY 2
#endif

#if defined(__linux) || defined(linux)
	# include "../libs/minilibx/mlx.h"
	# include "../libs/minilibx/mlx_int.h"
	# define ESC_KEY 65307
	# define W_KEY 119
	# define S_KEY 115
	# define A_KEY 97
	# define D_KEY 100
#endif

# include "../libs/ft_printf/ft_printf.h"
# include "../libs/get_next_line/get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_ambiance
{
	void	*img;
	int		width;
	int		height;
}			t_ambiance;

typedef struct s_sprite
{
	void	*img;
	int		x;
	int		y;
	int		items;
	int		width;
	int		height;
}			t_sprite;

typedef struct s_vars
{
	void		*mlx;
	void		*window;
	int			map_w;
	int			map_h;
	char		*map[200];
	int			collected;
	char		*exit_msg;
	t_sprite	player;
	t_sprite	enemy[100];
	t_ambiance	wall;
	t_ambiance	floor;
	t_ambiance	exit;
	t_ambiance	item;
}				t_vars;

int	dstr_w(t_vars *vars);
int	key_hook(int keycode, t_vars *vars);
int read_map (t_vars *vars, char *path);
int exit_now(t_vars *vars);
int init_vars(t_vars *vars);
int validate_map(t_vars *vars);

#endif
