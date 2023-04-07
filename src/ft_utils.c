/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 16:38:10 by imurugar          #+#    #+#             */
/*   Updated: 2023/02/27 15:53:04 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_so_long.h"

int	ft_count_lines(char *argc)
{
	int	lines;

	lines = 0;
	while (*argc)
	{
		if (*argc == '\n' || *(argc + 1) == '\0')
			lines++;
		argc++;
	}
	return (lines);
}

int	ft_count_row_size(char *argc)
{
	int	count;

	count = 0;
	while (*argc)
	{
		if (*argc != '\n')
			count++;
		else if (*argc == '\n')
			break ;
		argc++;
	}
	return (count);
}

int	char_count(char *line, int c)
{
	int	ret;

	ret = 0;
	while (*line)
		if (*line++ == c)
			++ret;
	return (ret);
}
