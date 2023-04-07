/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 22:54:13 by imurugar          #+#    #+#             */
/*   Updated: 2023/03/01 12:40:39 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_so_long.h"
#include "../libft/libft.h"
#include "../minilibx/mlx.h"

void	ft_init_values(t_game *game)
{
	game->movements = 0;
	game->map.c = 0;
	game->map.e = 0;
	game->map.p = 0;
	game->map.n = 0;
	game->map.tile = 32;
}

void	init_map(char *file, t_game *game)
{
	char			**map;
	char			*line;
	int				i;
	const int		fd = open(file, O_RDONLY);

	map = (char **)malloc((game->map.rows + 1) * sizeof(char *));
	if (!map)
		return ;
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		map[i] = line;
		line = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	game->map.lines = map;
}

void	init_images(t_game *game)
{
	int		w;
	int		h;
	void	*(*p)(void *, char *, int *, int *);

	p = mlx_xpm_file_to_image;
	w = 32;
	h = 32;
	game->p = p(game->mlx, "assets/pacman/0.xpm", &w, &h);
	game->c = p(game->mlx, "assets/dot.xpm", &w, &h);
	game->e = p(game->mlx, "assets/exit.xpm", &w, &h);
	game->o = p(game->mlx, "assets/wall.xpm", &w, &h);
}

void	update_values(t_game *g, int x, int y)
{
	static int	p_count;

	if (g->map.lines[y][x] == 'P')
	{
		g->player[p_count].x = x;
		g->player[p_count].y = y;
		g->player[p_count].next_x = x;
		g->player[p_count].next_y = y;
		g->player[p_count].direction = 0;
		g->player[p_count].current_step = 0;
		g->player[p_count].prev_step = 1;
		p_count++;
	}
}

void	init_player_enemies(t_game *g)
{
	t_player	*p;
	int			x;
	int			y;

	p = malloc(g->map.p * sizeof(t_player));
	if (p)
		g->player = p;
	y = 0;
	while (y < g->map.rows)
	{
		x = 0;
		while (x < g->map.cols)
		{
			update_values(g, x, y);
			x++;
		}
		y++;
	}
}
