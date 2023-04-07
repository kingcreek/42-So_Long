/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setup.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 22:54:20 by imurugar          #+#    #+#             */
/*   Updated: 2023/02/27 15:52:19 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SETUP_H
# define FT_SETUP_H

# include "ft_structs.h"

void	ft_init_values(t_game *game);
void	init_map(char *file, t_game *game);
void	init_images(t_game *game);
void	init_player_enemies(t_game *g);

#endif