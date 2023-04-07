/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pathval_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 17:46:34 by imurugar          #+#    #+#             */
/*   Updated: 2023/02/27 15:51:04 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_so_long.h"

int	count_c(char **map)
{
	int	x;
	int	y;
	int	c;

	x = 0;
	y = 0;
	c = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C')
				c++;
			x++;
		}
		y++;
	}
	return (c);
}

int	*search_is_p(char **map, int x, int y, char c)
{
	static int	end[2] = {0, 0};
	static int	s_x;
	static int	s_y;

	s_x = msx(map);
	s_y = msy(map);
	if (y < 0 || y >= s_y || x < 0 || x >= s_x
		|| map[y][x] == c || map[y][x] == 'N')
		return (NULL);
	if (map[y][x] == 'E')
		end[1] += 1;
	else if (map[y][x] == 'C')
		end[0] += 1;
	map[y][x] = c;
	search_is_p(map, x + 1, y, c);
	search_is_p(map, x, y + 1, c);
	search_is_p(map, x, y - 1, c);
	search_is_p(map, x - 1, y, c);
	return (end);
}

int	find_p_x(char **map, char c)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x++])
		{
			if (map[y][x] == c)
				return (x);
		}
		y++;
	}
	return (0);
}

int	find_p_y(char **map, char c)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == c)
				return (y);
			x++;
		}
		y++;
	}
	return (0);
}

int	check_is_possible(char *file, t_game *g)
{
	char	**map;
	int		*check;
	int		x;
	int		y;
	int		c;

	map = copy_map(file, g);
	if (!map)
		return (0);
	c = count_c(map);
	x = find_p_x(map, 'P');
	y = find_p_y(map, 'P');
	check = search_is_p(map, x, y, '1');
	free_all(map, g->map.rows);
	if (check[0] == c && check[1] == 1)
		return (1);
	return (0);
}
