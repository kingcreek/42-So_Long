/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 14:44:58 by imurugar          #+#    #+#             */
/*   Updated: 2023/02/27 15:52:47 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_so_long.h"
#include "../libft/libft.h"
#include "../minilibx/mlx.h"

int	ft_check_map(char *file, t_game *g)
{
	if (!ft_strend_cmp(file, ".ber") || !ft_is_rectangle(file, &g->map) \
	|| !check_is_possible(file, g))
		return (0);
	return (1);
}

void	add_images_to_game(t_game *g)
{
	int	x;
	int	y;
	int	(*put_img)(void *, void *, void *, int x, int y);

	put_img = mlx_put_image_to_window;
	y = 0;
	while (y < g->map.rows)
	{
		x = 0;
		while (x < g->map.cols)
		{
			if (g->map.lines[y][x] == '1')
				put_img(g->mlx, g->win, g->o, g->map.tile * x, g->map.tile * y);
			else if (g->map.lines[y][x] == 'C')
				put_img(g->mlx, g->win, g->c, g->map.tile * x, g->map.tile * y);
			else if (g->map.lines[y][x] == 'E')
				put_img(g->mlx, g->win, g->e, g->map.tile * x, g->map.tile * y);
			else if (g->map.lines[y][x] == 'P')
				put_img(g->mlx, g->win, g->p, g->map.tile * x, g->map.tile * y);
			x++;
		}
		y++;
	}
}
