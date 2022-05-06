#include "so_long.h"

int ft_verif_name_map(char *name)
{
	int len;

	len = ft_strlen(name) - 1;

	if(name[len-3] != '.' || name[len-2] != 'b' || name[len-1] != 'e' || name[len] != 'r')
	{
		write(2, "Error\n", 7);
		write(2,"EXTENTION NON VALIDE\n",22);
		return (0);
	}
	if(3 >= len)
	{
		write(2, "Error\n", 7);
		write(2,"NOM DE MAP ERRONE\n",19);
		return (0);
	}

	return (1);
}
