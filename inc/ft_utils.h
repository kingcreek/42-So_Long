/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 16:37:11 by imurugar          #+#    #+#             */
/*   Updated: 2023/02/27 15:52:30 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H

# include "ft_structs.h"

int		ft_count_lines(char *argc);
int		ft_count_row_size(char *argc);
int		char_count(char *line, int c);
int		ft_ram_seed(int to);
void	process_key(int keycode, int p_c, t_game *g);

#endif