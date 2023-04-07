/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:10:37 by imurugar          #+#    #+#             */
/*   Updated: 2023/02/28 15:49:17 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_so_long.h"
#include "../minilibx/mlx.h"

/**
 * It frees all the memory allocated by the game, and then exit
 * 
 * @param g the game structure
 */
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
	if (g->player)
		free(g->player);
	mlx_destroy_image(g->mlx, g->o);
	mlx_destroy_image(g->mlx, g->c);
	mlx_destroy_image(g->mlx, g->e);
	mlx_destroy_image(g->mlx, g->p);
	mlx_clear_window(g->mlx, g->win);
	mlx_destroy_window(g->mlx, g->win);
	mlx_destroy(g->mlx);
	exit(0);
}

/**
 * It takes the player's next x and y coordinates and sets them 
 * to the current x and y coordinates
 * 
 * @param g the game struct
 */
void	process_movement(t_game *g)
{
	int		nx;
	int		ny;
	int		p_count;

	p_count = 0;
	while (p_count < g->map.p)
	{
		nx = g->player[p_count].next_x;
		ny = g->player[p_count].next_y;
		g->map.lines[g->player[p_count].y][g->player[p_count].x] = '0';
		g->player[p_count].x = g->player[p_count].next_x;
		g->player[p_count].y = g->player[p_count].next_y;
		g->map.lines[g->player[p_count].y][g->player[p_count].x] = 'P';
		p_count++;
	}
	mlx_clear_window(g->mlx, g->win);
	add_images_to_game(g);
	g->movements = g->movements + 1;
}

/**
 * It checks if the player is trying to move into a wall, 
 * and if not, it checks if the player is trying
 * to move into an exit, and if not, it checks if the player 
 * is trying to move into a collectable, and
 * if not, it checks if the player is trying to move into the 
 * end of the game, and if not, it moves the
 * player
 * 
 * @param g the game structure
 * @param keycode the key pressed by the player
 * @param p_c player count
 * 
 * @return the value of the variable "keycode"
 */
void	process(t_game *g, int keycode, int p_c)
{
	if (keycode == UP)
		g->player[p_c].next_y = g->player[p_c].y - 1;
	else if (keycode == DOWN)
		g->player[p_c].next_y = g->player[p_c].y + 1;
	else if (keycode == LEFT)
		g->player[p_c].next_x = g->player[p_c].x - 1;
	else if (keycode == RIGHT)
		g->player[p_c].next_x = g->player[p_c].x + 1;
	if (g->map.lines[g->player[p_c].next_y][g->player[p_c].next_x] != '1')
	{
		if (g->map.lines[g->player[p_c].next_y][g->player[p_c].next_x] == 'E'
			&& g->map.c != 0)
		{
			revert_step(g, keycode, p_c);
			return ;
		}
		compute_collectable(g, p_c);
		check_endgame(g, p_c);
		process_movement(g);
	}
	else
	{
		g->player[p_c].next_x = g->player[p_c].x;
		g->player[p_c].next_y = g->player[p_c].y;
	}
}

/**
 * It takes the keycode and the game struct as parameters, 
 * and then it loops through the players and
 * calls the process function on each one
 * 
 * @param keycode the key that was pressed
 * @param game the game struct
 * 
 * @return The keycode of the key pressed.
 */
int	key_hook(int keycode, t_game *game)
{
	int		p_c;

	p_c = 0;
	if (keycode == UP || keycode == DOWN
		|| keycode == LEFT || keycode == RIGHT)
	{
		while (p_c < game->map.p)
		{
			process(game, keycode, p_c);
			p_c++;
		}
		printf("%d\n", game->movements);
	}
	if (keycode == ESC)
	{
		game->map.c = 1;
		exit_game(game);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	ft_init_values(&game);
	if (argc == 2 && ft_check_map(argv[1], &game))
	{
		init_map(argv[1], &game);
		game.mlx = mlx_init();
		game.win = mlx_new_window(game.mlx, game.map.cols * game.map.tile, \
				game.map.rows * game.map.tile, "so_long - imurugar");
		init_images(&game);
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
