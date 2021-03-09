#include "header/my_type.h"

void	clear_param(char **screen)
{
	int	i;

	i = 0;
	while (screen[i])
	{
		free(screen[i]);
		screen[i] = NULL;
		i++;
	}
	free(screen);
}
