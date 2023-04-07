/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 21:33:10 by imurugar          #+#    #+#             */
/*   Updated: 2023/02/27 15:52:00 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GAME_UTILS_H
# define FT_GAME_UTILS_H

# include "ft_structs.h"

void	destroy_player_enemy(t_game *g);
void	revert_step(t_game *g, int keycode, int p_c);
void	compute_collectable(t_game *g, int p_c);
void	check_endgame(t_game *g, int p_c);

#endif