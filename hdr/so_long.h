#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx/mlx.h"
# include "../minilibx/mlx_int.h"

typedef struct s_mlx
{
	void	*mlx;
	void	*window;
	int		win_x;
	int		win_y;
}			t_mlx;

int dstr_w(t_mlx *mlx);

#endif
