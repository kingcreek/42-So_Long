/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 16:38:10 by imurugar          #+#    #+#             */
/*   Updated: 2023/02/27 15:51:17 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_so_long.h"
#include "../minilibx/mlx.h"

int	ft_count_lines(char *argc)
{
	int	lines;

	lines = 0;
	while (*argc)
	{
		if (*argc == '\n' || *(argc + 1) == '\0')
			lines++;
		argc++;
	}
	return (lines);
}

int	ft_count_row_size(char *argc)
{
	int	count;

	count = 0;
	while (*argc)
	{
		if (*argc != '\n')
			count++;
		else if (*argc == '\n')
			break ;
		argc++;
	}
	return (count);
}

int	char_count(char *line, int c)
{
	int	ret;

	ret = 0;
	while (*line)
		if (*line++ == c)
			++ret;
	return (ret);
}

int	ft_ram_seed(int to)
{
	static int	g_seed;

	g_seed = (214013 * g_seed + 2531011);
	return ((g_seed >> 16) & to);
}

void	process_key(int keycode, int p_c, t_game *g)
{
	if (keycode == UP)
		g->player[p_c].next_y = g->player[p_c].y - 1;
	else if (keycode == DOWN)
		g->player[p_c].next_y = g->player[p_c].y + 1;
	else if (keycode == LEFT)
		g->player[p_c].next_x = g->player[p_c].x - 1;
	else if (keycode == RIGHT)
		g->player[p_c].next_x = g->player[p_c].x + 1;
}
