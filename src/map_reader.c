# include "../hdr/so_long.h"

int read_map (t_vars *vars, char *path)
{
	int	i;
	int	fd;
	char	str;

	i = 0;
	fd = open(path, O_RDONLY);
	str = get_next_line(fd);

}
