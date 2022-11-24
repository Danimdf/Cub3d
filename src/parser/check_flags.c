/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 02:19:58 by coder             #+#    #+#             */
/*   Updated: 2022/11/23 20:50:05 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_flags_cardinal_directions(char *line, int counter)
{
	if ((!ft_strncmp(line, "NO ", 3) && counter == 0)
	|| (!ft_strncmp(line, "SO ", 3) && counter == 1)
	|| (!ft_strncmp(line, "WE ", 3) && counter == 2)
	|| (!ft_strncmp(line, "EA ", 3) && counter == 3))
		return (1);

	return (0);
}

int	check_flags_colors(char *line)
{
	if (!ft_strncmp(line, "F ", 2) ||
	!ft_strncmp(line, "C ", 2))
		return (1);

	return (0);
}

void	add_char_lines(t_data *data)
{
	int i;
	size_t j;
	size_t	len_num;

	i = 0;
	len_num = data->big_line + 1;
	while(data->map[i] != NULL)
	{
		j = 0;
		while (j < len_num)
		{
			if (ft_strlen(data->map[i]) <= len_num)
				ft_strlcat(data->map[i], "D", len_num);
			j++;
		}
		i++;
	}
}
