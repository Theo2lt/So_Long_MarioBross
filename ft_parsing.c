#include "so_long.h"



char	**ft_create_tab(char *name_map)
{
	int		fd;
	char	*str;
	int		i;
	int		len;
	char	**tab;

	str = "";
	i = 0;

	if(!ft_verif_name_map(name_map))
		return(NULL);

	fd = open(name_map,O_RDONLY);
	if(fd == -1)
	{
		write(2, "Error\n", 7);
		write(2,"ACCES MAP INVALIDE \n",21);
		return(NULL);
	}

	while(str)
	{
		i++;
		str = get_next_line(fd);
		free(str);
	}
	tab	= malloc(sizeof(char *) * i);
	close(fd);
	len = i;
	i = 0;
	fd = open(name_map,O_RDONLY);
	str = "";
	while(len != i)
	{
		tab[i] = get_next_line(fd);
		if(tab[i])
			tab[i][ft_strlen(tab[i])] = '\0';
		i++;
	}
	close(fd);
	return (tab);
}
