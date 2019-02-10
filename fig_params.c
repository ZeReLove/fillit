#include "fillit.h"

int	ft_tetr_height(char *buff)
{
	int	height;
	int	count;
	int	block_count;

	while (*buff != '#')
		buff++;
	while (*buff != '\n')
		buff++;
	buff -= 4;
	while(buff)
	{
		buff++;
		count++;
		if (*buff == '#')
			block_count++;
		if (block_count == 4)
		{
			while (*buff != '/n')
			{
				buff++;
				count++;
			}
			return (count / 5);
		}
	}
	return (0);
}
