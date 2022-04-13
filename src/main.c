#include "../hdr/so_long.h"

int main(void)
{
	void *mlx_ptr;
	mlx_ptr  = mlx_init();
	mlx_new_window(mlx_ptr, 512, 512, "Hello_window");
	sleep(5);

}
