/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_anim_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:50:36 by imurugar          #+#    #+#             */
/*   Updated: 2023/03/07 16:01:56 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_so_long.h"
#include "../libft/libft.h"
#include "../minilibx/mlx.h"

/**
 * It initializes the player's animations
 * 
 * @param game the game struct
 * @param w width of the image
 * @param h height of the image
 */
void	init_player_anims(t_game *game, int w, int h)
{
	char		c[2];
	char		*join;
	char		*join2;
	t_anim		*a;
	void		*(*p)(void *, char *, int *, int *);

	p = mlx_xpm_file_to_image;
	a = malloc(9 * sizeof(t_anim));
	if (a)
		game->p = a;
	c[0] = '0';
	c[1] = '\0';
	while (c[0] < '9')
	{
		join = ft_strjoin("assets/pacman/", c);
		join2 = ft_strjoin(join, ".xpm");
		game->p[c[0] - '0'].a = p(game->mlx, join2, &w, &h);
		free(join);
		free(join2);
		c[0]++;
	}
}

void	init_enemi_anims(t_game *game, int w, int h)
{
	char		c[2];
	char		*join;
	char		*join2;
	t_anim		*a;
	void		*(*p)(void *, char *, int *, int *);

	p = mlx_xpm_file_to_image;
	a = malloc(8 * sizeof(t_anim));
	if (a)
		game->n = a;
	c[0] = '0';
	c[1] = '\0';
	while (c[0] < '8')
	{
		join = ft_strjoin("assets/ghost/", c);
		join2 = ft_strjoin(join, ".xpm");
		game->n[c[0] - '0'].a = p(game->mlx, join2, &w, &h);
		free(join);
		free(join2);
		c[0]++;
	}
}
