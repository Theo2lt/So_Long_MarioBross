#include "so_long.h"

int ft_verif_arg(int argc)
{
	if(argc != 2)
	{
		write(2, "Error\n", 7);
		write(2,"ARG invalid\n",13);
		return(0);
	}
	return(1);
}
