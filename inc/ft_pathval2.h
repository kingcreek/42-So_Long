/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pathval2.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 17:42:57 by imurugar          #+#    #+#             */
/*   Updated: 2023/02/15 17:52:17 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PATHVAL2_H
# define FT_PATHVAL2_H

# include "ft_structs.h"

int		msx(char **map);
int		msy(char **map);
char	**copy_map(char *file, t_game *g);
char	**free_all(char **map, int i);

#endif