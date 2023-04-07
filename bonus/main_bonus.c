/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 14:34:24 by imurugar          #+#    #+#             */
/*   Updated: 2023/03/06 17:04:01 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_so_long.h"
#include "../minilibx/mlx.h"

int	exit_game(t_game *g)
{
	char	**tmp;

	if (g->map.c == 0)
		printf("You win!\n");
	else
		printf("You lose!\n");
	tmp = g->map.lines;
	while (*tmp)
		free(*tmp++);
	free(g->map.lines);
	destroy_player_enemy(g);
	mlx_destroy_image(g->mlx, g->o);
	mlx_destroy_image(g->mlx, g->c);
	mlx_destroy_image(g->mlx, g->e);
	mlx_clear_window(g->mlx, g->win);
	mlx_destroy_window(g->mlx, g->win);
	mlx_destroy(g->mlx);
	exit(0);
}

void	process_movement(t_game *g, int keycode)
{
	int		p_count;

	p_count = 0;
	while (p_count < g->map.p)
	{
		compute_direction(keycode, g, p_count);
		g->map.lines[g->player[p_count].y][g->player[p_count].x] = '0';
		g->player[p_count].x = g->player[p_count].next_x;
		g->player[p_count].y = g->player[p_count].next_y;
		g->map.lines[g->player[p_count].y][g->player[p_count].x] = 'P';
		p_count++;
	}
	process_enemies_movement(g);
	mlx_clear_window(g->mlx, g->win);
	add_images_to_game(g);
	g->movements = g->movements + 1;
}

void	process(t_game *g, int keycode, int p_c)
{
	process_key(keycode, p_c, g);
	if (g->map.lines[g->player[p_c].next_y][g->player[p_c].next_x] != '1' \
	&& g->map.lines[g->player[p_c].next_y][g->player[p_c].next_x] != 'P')
	{
		if (g->map.lines[g->player[p_c].next_y][g->player[p_c].next_x] == 'N'
		|| g->map.lines[g->player[p_c].next_y][g->player[p_c].next_x] == 'c')
			exit_game(g);
		if (g->map.lines[g->player[p_c].next_y][g->player[p_c].next_x] == 'E'
			&& g->map.c != 0)
		{
			revert_step(g, keycode, p_c);
			return ;
		}
		compute_collectable(g, p_c);
		check_endgame(g, p_c);
		process_movement(g, keycode);
	}
	else
	{
		g->player[p_c].next_x = g->player[p_c].x;
		g->player[p_c].next_y = g->player[p_c].y;
	}
}

int	key_hook(int keycode, t_game *g)
{
	char	*moves;
	int		p_c;

	p_c = 0;
	if (keycode == UP || keycode == DOWN
		|| keycode == LEFT || keycode == RIGHT)
	{
		while (p_c < g->map.p)
		{
			process(g, keycode, p_c);
			p_c++;
		}
		moves = ft_itoa(g->movements);
		mlx_string_put(g->mlx, g->win, 15 \
		, g->map.rows * g->map.tile + 10, 0x00FFFFFF, moves);
		free(moves);
	}
	if (keycode == ESC)
	{
		g->map.c = 1;
		exit_game(g);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;
	char	*moves;

	ft_init_values(&game);
	if (argc == 2 && ft_check_map(argv[1], &game))
	{
		init_map(argv[1], &game);
		game.mlx = mlx_init();
		game.win = mlx_new_window(game.mlx, game.map.cols * game.map.tile, \
				game.map.rows * game.map.tile + 10, "so_long - imurugar");
		init_images(&game);
		moves = ft_itoa(game.movements);
		mlx_string_put(game.mlx, game.win, 15 \
		, game.map.rows * game.map.tile + 10, 0x00FFFFFF, moves);
		free(moves);
		init_player_enemies(&game);
		add_images_to_game(&game);
		mlx_hook(game.win, 17, 0, exit_game, &game);
		mlx_key_hook(game.win, key_hook, &game);
		mlx_loop(game.mlx);
	}
	else
		printf("Error: Expected map not found\n");
	return (0);
}
