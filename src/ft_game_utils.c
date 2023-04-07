/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 21:34:26 by imurugar          #+#    #+#             */
/*   Updated: 2023/02/27 16:06:13 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_so_long.h"
#include "../minilibx/mlx.h"

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
	if (g->map.lines[g->player[p_c].next_y][g->player[p_c].next_x] == 'E')
		exit_game(g);
}
