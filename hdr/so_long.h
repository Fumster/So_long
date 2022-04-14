#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libs/minilibx/mlx.h"
# include "../libs/minilibx/mlx_int.h"
# include "../libs/ft_printf/ft_printf.h"

typedef struct s_mlx
{
	void	*mlx;
	void	*window;
	int		win_x;
	int		win_y;
}			t_mlx;

int	dstr_w(t_mlx *mlx);
int	key_hook(int keycode, void *mlx);

#endif
