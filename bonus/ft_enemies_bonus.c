/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemies_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:50:41 by imurugar          #+#    #+#             */
/*   Updated: 2023/02/27 15:50:43 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_so_long.h"
#include "../minilibx/mlx.h"

void	check_end_game(t_game *g, int nx, int ny)
{
	int	p;

	p = 0;
	while (p < g->map.p)
	{
		if (g->player[p].x == nx && g->player[p].y == ny)
			exit_game(g);
		p++;
	}
}

void	compute_random(t_enemy *t, int *nx, int *ny)
{
	if (ft_ram_seed(0x01))
	{
		if (ft_ram_seed(0x01))
		{
			*nx += 1;
			t->direction = 4;
			return ;
		}
		*nx -= 1;
		t->direction = 2;
	}
	else
	{
		if (ft_ram_seed(0x01))
		{
			*ny += 1;
			t->direction = 0;
			return ;
		}
		*ny -= 1;
		t->direction = 6;
	}
}

void	set_position(t_enemy *t, t_game *g)
{
	int	nx;
	int	ny;

	nx = t->x;
	ny = t->y;
	compute_random(t, &nx, &ny);
	if (g->map.lines[ny][nx] != '1' && g->map.lines[ny][nx] != 'E' && \
	g->map.lines[ny][nx] != 'N' && g->map.lines[ny][nx] != 'c')
	{
		check_end_game(g, nx, ny);
		if (g->map.lines[t->y][t->x] == 'C' || g->map.lines[t->y][t->x] == 'c')
			g->map.lines[t->y][t->x] = 'C';
		else
			g->map.lines[t->y][t->x] = '0';
		t->x = nx;
		t->y = ny;
		if (g->map.lines[t->y][t->x] == 'C' || g->map.lines[t->y][t->x] == 'c')
			g->map.lines[t->y][t->x] = 'c';
		else
			g->map.lines[t->y][t->x] = 'N';
	}
}

void	process_enemies_movement(t_game *g)
{
	int	e;

	e = 0;
	while (e < g->map.n)
	{
		set_position(&g->enemies[e], g);
		e++;
	}
}
