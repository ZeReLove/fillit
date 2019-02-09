/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconwy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 18:16:01 by bconwy            #+#    #+#             */
/*   Updated: 2019/02/01 18:16:04 by bconwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int ft_connect_tetrimino(char *buff)
{
    int connect_count;

    while (buff)
    {
        connect_count = 0;
        while (!(*buff == '\n'))
        {
            while (*buff != '#' || (!(*buff = '\n' && *(buff + 1) = '\n')))
                buff++;
            if (*(buff + 1) == '#')
                connect_count++;
            if (*(buff - 1) == '#')
                connect_count++;
            if (*(buff + 5) == '#')
                connect_count++;
            if (*(buff - 5) == '#')
                connect_count++;
            buff++;
        }
        if (connect_count != 6 || connect_count != 8)
            return (-1);
        buff++;
    }
    
}

int	ft_valid_tetr(char *buff)
{
	int	block_count;

	while (buff)
	{
		while (!(*buff = '\n' && *(buff + 1) = '\n'))
		{
			if (*buff != '\n' || *buff != '#' || *buff != '.')
				return (-1);
			if (*buff == '#')
				block_count++;
			buff++;
		}
		if (block_count != 4)
				return (-1);
		buff++;
	}
}

int	ft_valid_tetrimino(char *buff)
{
	int	tetr_count;
	int	char_count;
	int line_count;

    char_count = 0;
    line_count = 0;
    tetr_count = 0;
	while (buff)
	{
		while (!(*buff == '\n' && *buff == '\0'))
		{
			while (*buff != '\n')
			{
				buff++;
				char_count++;
			}
			if (char_count != 4)
				return (-1);
			line_count++;
			buff++;
		}
		if (line_count != 4)
				return (-1);
		tetr_count++;
        if (*buff == '\0')
            return (-1);
		buff++;
	}
	if (!(tetr_count >= 1 && tetr_count <= 26))
		return (-1);
	return (1);
}

int	ft_read_file(char *file_name)
{
	int		fd;
	char	buff[BUFF_SIZE];
	int		ret;

    if (!(file_name))
        return (-1);
	fd = open(file_name, O_RDONLY);
    if (fd < 0 || fd > BUFF_SIZE)
		return (-1);
	if ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
        if (close(fd) == -1)
            return (-1);
		return (1);
	}
    if (close(fd) == -1)
            return (-1);
	return (-1);
}
