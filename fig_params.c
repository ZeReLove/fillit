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

void    ft_tetr_width(char *buff, t_fig *f)
{
        int width;

        width = 1;
        while (buff)
        {
            if (*buff == '#' && *(buff + 1) == '#' && *(buff + 5) == '#')
                fig->width = 2;
            buff++;
        }
        buff -= 21;
        while (buff)
        {
            if (*buff == '#' && *(buff + 1) == '#')
                width++;
            buff++;
        }
        fig->width = width;                                                                                                          v
}
