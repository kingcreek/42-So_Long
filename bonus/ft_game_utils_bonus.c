/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:50:48 by imurugar          #+#    #+#             */
/*   Updated: 2023/02/27 15:50:50 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_so_long.h"
#include "../minilibx/mlx.h"

void	destroy_player_enemy(t_game *g)
{
	int	c;

	if (g->player)
		free(g->player);
	if (g->enemies)
		free(g->enemies);
	c = 0;
	while (c < 9)
	{
		mlx_destroy_image(g->mlx, g->p[c].a);
		c++;
	}
	free(g->p);
	c = 0;
	while (c < 8)
	{
		mlx_destroy_image(g->mlx, g->n[c].a);
		c++;
	}
	free(g->n);
}

void	revert_step(t_game *g, int keycode, int p_c)
{
	if (keycode == UP)
		g->player[p_c].next_y = g->player[p_c].y;
	else if (keycode == DOWN)
		g->player[p_c].next_y = g->player[p_c].y;
	else if (keycode == LEFT)
		g->player[p_c].next_x = g->player[p_c].x;
	else if (keycode == RIGHT)
		g->player[p_c].next_x = g->player[p_c].x;
}

void	compute_collectable(t_game *g, int p_c)
{
	if (g->map.lines[g->player[p_c].next_y][g->player[p_c].next_x] == 'C')
			g->map.c--;
}

void	check_endgame(t_game *g, int p_c)
{
	if (g->map.lines[g->player[p_c].next_y][g->player[p_c].next_x] == 'E'
		|| g->map.lines[g->player[p_c].next_y][g->player[p_c].next_x] == 'c')
		exit_game(g);
}
