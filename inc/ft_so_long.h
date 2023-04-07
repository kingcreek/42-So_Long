/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 14:34:39 by imurugar          #+#    #+#             */
/*   Updated: 2023/02/15 17:41:50 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SO_LONG_H
# define FT_SO_LONG_H

# define ESC 53
# define LEFT 0
# define RIGHT 2
# define DOWN 1
# define UP 13

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include "../getnextline/get_next_line.h"
# include "../libft/libft.h"
# include "ft_map_validate.h"
# include "ft_utils.h"
# include "ft_map.h"
# include "ft_structs.h"
# include "ft_setup.h"
# include "ft_anim.h"
# include "ft_game_utils.h"
# include "ft_enemies.h"
# include "ft_pathval.h"
# include "ft_pathval2.h"

int	exit_game(t_game *g);

#endif