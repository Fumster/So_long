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
	# define W_KEY 13
	# define S_KEY 1
	# define A_KEY 0
	# define D_KEY 2
#endif

# include "../libs/ft_printf/ft_printf.h"
# include <stdlib.h>
# include <unistd.h>

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
	char		**map;
	int			collected;
	t_sprite	player;
	t_sprite	enemy[50];
	t_ambiance	wall;
	t_ambiance	floor;
	t_ambiance	exit;
	t_ambiance	item;
}				t_vars;

int	dstr_w(t_vars *vars);
int	key_hook(int keycode, t_vars *vars);

#endif
