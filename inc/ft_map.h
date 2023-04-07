/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 14:44:51 by imurugar          #+#    #+#             */
/*   Updated: 2023/02/27 15:52:07 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAP_H
# define FT_MAP_H

# include "ft_structs.h"

int		ft_check_map(char *file, t_game *g);
void	add_images_to_game(t_game *game);
void	compute_direction(int keycode, t_game *g, int p_count);

#endif