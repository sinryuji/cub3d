#include "../lib/libft/include/libft.h"
#include "../lib/mlx/mlx.h"
#include <stdio.h>

int	main(void)
{
	printf("Hello, cub3d!\n");
	ft_putchar_fd('a', 1);
	mlx_put_image_to_window((void *)0, (void *)0, (void *)0, 0, 0);
	return (0);
}

