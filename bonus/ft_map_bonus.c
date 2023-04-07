/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 14:44:58 by imurugar          #+#    #+#             */
/*   Updated: 2023/03/07 16:02:20 by imurugar         ###   ########.fr       */
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

/**
 * It puts the player's image
 * on the screen
 * 
 * @param g the game struct
 * @param y the y coordinate of the tile
 * @param x x coordinate of the tile
 * @param put_img a function pointer to the function that will 
 * put the image on the screen
 */
void	process_player_img(t_game *g, int y, int x
		, int (*put_img)(void *, void *, void *, int x, int y))
{
	int	st;
	int	c;

	c = -1;
	while (++c < g->map.p)
	{
		st = g->player[c].direction + g->player[c].current_step;
		if (g->player[c].current_step == 0)
			put_img(g->mlx, g->win, g->p[0].a, g->map.tile * x, \
					g->map.tile * y);
		else
			put_img(g->mlx, g->win, g->p[st].a, g->map.tile * x, \
					g->map.tile * y);
		if (g->player[c].current_step > 1)
			g->player[c].prev_step = -1;
		else if (g->player[c].current_step < 1)
			g->player[c].prev_step = 1;
		g->player[c].current_step += g->player[c].prev_step;
	}
}

void	process_enemy_img(t_game *g, int y, int x
		, int (*put_img)(void *, void *, void *, int x, int y))
{
	int	st;
	int	c;

	c = -1;
	while (++c < g->map.n)
	{
		if (g->enemies[c].x != x && g->enemies[c].y != y)
			continue ;
		st = g->enemies[c].direction + g->enemies[c].current_step;
		if (g->enemies[c].current_step == 0)
		{
			put_img(g->mlx, g->win, g->n[g->enemies[c].direction].a, \
				g->map.tile * x, g->map.tile * y);
			g->enemies[c].current_step += 1;
		}
		else
		{
			put_img(g->mlx, g->win, g->n[st].a, g->map.tile * x, \
				g->map.tile * y);
			g->enemies[c].current_step -= 1;
		}
	}
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
				process_player_img(g, y, x, put_img);
			else if (g->map.lines[y][x] == 'N' || g->map.lines[y][x] == 'c')
				process_enemy_img(g, y, x, put_img);
			x++;
		}
		y++;
	}
}

void	compute_direction(int keycode, t_game *g, int p_count)
{
	if (keycode == UP)
		g->player[p_count].direction = 2;
	else if (keycode == DOWN)
		g->player[p_count].direction = 0;
	else if (keycode == LEFT)
		g->player[p_count].direction = 6;
	else if (keycode == RIGHT)
		g->player[p_count].direction = 4;
}
