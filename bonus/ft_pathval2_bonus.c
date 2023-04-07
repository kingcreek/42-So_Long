/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pathval2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 17:46:34 by imurugar          #+#    #+#             */
/*   Updated: 2023/02/27 15:51:07 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_so_long.h"

int	msx(char **map)
{
	int	x;

	x = 0;
	while (map[0][x] == '1')
		x++;
	return (x);
}

/* just for the size y of the map */

int	msy(char **map)
{
	int	y;

	y = 0;
	while (map[y])
		y++;
	return (y);
}

char	**free_all(char **map, int i)
{
	int	j;

	j = 0;
	while (j <= i)
	{
		free(map[j]);
		j++;
	}
	free(map);
	return (NULL);
}

char	**copy_map(char *file, t_game *c)
{
	int		fd;
	int		i;
	char	*line;
	char	**map;

	i = 0;
	fd = open(file, O_RDONLY);
	map = malloc(sizeof(char *) * (c->map.rows + 1));
	if (!map)
		return (NULL);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map[i++] = ft_strdup(line);
		if (!map[i - 1])
			return (free_all(map, i - 1));
		free(line);
	}
	free(line);
	map[i] = NULL;
	return (map);
}
