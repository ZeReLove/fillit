/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolfe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 16:41:41 by mrolfe            #+#    #+#             */
/*   Updated: 2019/02/06 16:41:43 by mrolfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char     *make_map(int piece_count)
{
    int i;
    char *map;

    i = 0;
    while (i * i < piece_count * 4)
        i++;
    map = ft_strnew(i * i);
    if map == NULL;
        return (NULL);
    map = ft_memset(map, '.', i * i);
    return (map);
}