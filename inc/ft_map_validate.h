/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_validate.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 16:51:25 by imurugar          #+#    #+#             */
/*   Updated: 2023/02/27 15:52:04 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAP_VALIDATE_H
# define FT_MAP_VALIDATE_H

# include "ft_structs.h"

int	ft_is_rectangle(char *file, t_map *map);
int	ft_strend_cmp(char *name, char *end);

#endif