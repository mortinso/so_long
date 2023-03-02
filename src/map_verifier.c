#include "so_long.h"

int	check_map(t_game *var, int fd)
{
	char	**map;
	char	*valid;
	char	buf;
	int		x;
	int		y;

	x = 0;
	y = 0;
	valid = "01PEC";
	if (read(fd, NULL, 0) < 0)
		return (NULL);
	while (1)
	{
		buf = read(fd, buf, 1);
	}
}