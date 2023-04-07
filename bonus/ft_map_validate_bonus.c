/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_validate_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 16:51:27 by imurugar          #+#    #+#             */
/*   Updated: 2023/02/28 14:33:30 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_so_long.h"
#include "../libft/libft.h"

int	ft_strend_cmp(char *name, char *end)
{
	int	name_len;
	int	ext_len;

	name_len = ft_strlen(name);
	ext_len = ft_strlen(end);
	if (name_len <= ext_len)
		return (0);
	name += name_len - ext_len;
	while (*name)
	{
		if (*name != *end)
			return (0);
		name++;
		end++;
	}
	return (1);
}

int	ft_correct_value(char *line, int i, t_map *map)
{
	int		pos;

	pos = 0;
	while (line[pos])
	{
		if ((i == 1 || i == map->rows || pos == 0 || pos == map->cols)
			&& line[pos] != '1')
			return (0);
		if (line[pos] != '1' && line[pos] != '0' && line[pos] != 'C'
			&& line[pos] != 'E' && line[pos] != 'P' && line[pos] != 'N')
			return (0);
		pos++;
	}
	return (1);
}

int	ft_map_are_closed(char *file, t_map *map)
{
	char			*line;
	int				i;
	const int		fd = open(file, O_RDONLY);

	i = 0;
	line = get_next_line(fd);
	while (line && ++i)
	{
		if (!ft_correct_value(line, i, map))
		{
			free(line);
			close(fd);
			return (0);
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (1);
}

void	ft_count_map_values(char *line, t_map *map)
{
	map->c += char_count(line, 'C');
	map->e += char_count(line, 'E');
	map->p += char_count(line, 'P');
	map->n += char_count(line, 'N');
}

int	ft_is_rectangle(char *file, t_map *map)
{
	char			*line;
	int				i;
	const int		fd = open(file, O_RDONLY);

	i = 0;
	line = get_next_line(fd);
	while (line && ++i)
	{
		if (i == 1)
			map->cols = ft_strlen(line);
		else if (map->cols != (int)ft_strlen(line))
		{
			free(line);
			return (0);
		}
		ft_count_map_values(line, map);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	map->rows = i;
	if (!map->c || map->e != 1 || map->p != 1 || map->rows < 3)
		return (0);
	return (ft_map_are_closed(file, map));
}
