#include "../libft/libft.h"

int	main(int argc, char **argv)
{
	int		fd;
	int		i;
	char	*line;
	char	**tab;

	(void)argc;
	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	printf("%s", line);
	tab = ft_split(line, ' ');
	i = 0;
	while (tab[i] != NULL)
	{
		printf("y= %d, z =%s\n", i, tab[i]);
		i++;
	}
	return (0);
}
