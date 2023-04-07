/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_structs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 15:48:53 by imurugar          #+#    #+#             */
/*   Updated: 2023/02/27 15:52:26 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRUCTS_H
# define FT_STRUCTS_H

typedef struct s_anim
{
	void		*a;
}	t_anim;

typedef struct s_map
{
	int		rows;
	int		cols;
	int		c;
	int		e;
	int		p;
	int		n;
	int		tile;
	char	**lines;
}	t_map;

typedef struct s_player
{
	int	x;
	int	y;
	int	next_x;
	int	next_y;	
	int	direction;
	int	current_step;
	int	prev_step;
}	t_player;

typedef struct s_enemy
{
	int	x;
	int	y;
	int	direction;
	int	current_step;
}	t_enemy;

typedef struct s_game
{
	t_player	*player;
	t_enemy		*enemies;
	int			movements;
	void		*o;
	void		*c;
	void		*e;
	t_anim		*p;
	t_anim		*n;
	void		*mlx;
	void		*win;
	t_map		map;
}	t_game;

#endif