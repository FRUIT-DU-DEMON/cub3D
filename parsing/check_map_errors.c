/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 04:36:06 by hlabouit          #+#    #+#             */
/*   Updated: 2024/01/04 00:40:09 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"parsing.h"

void	check_map_extension(char **av)
{
	int j;

	j = 0;
	while (av[1][j])
		j++;
	if (av[1][j - 1] == 'b' && av[1][j - 2] == 'u' && av[1][j - 3] == 'c' && av[1][j - 4] == '.')
		return;
	else
		display_errors(101);
}

void	check_map_characters(char **map_code)
{
	int	i;
	int	j;
	int	flag;

	flag = 0;
	i = 0;
	while (map_code[i])
	{
		j = 0;
		while (map_code[i][j])
		{
			if (map_code[i][j] != '0' && map_code[i][j] != '1'
				&& map_code[i][j] != 'N' && map_code[i][j] != 'S'
				&& map_code[i][j] != 'E' && map_code[i][j] != 'W'
				&& map_code[i][j] != ' ')
					display_errors(505);
			if (map_code[i][j] =='N' || map_code[i][j] =='S'
				|| map_code[i][j] =='E' || map_code[i][j] =='W')
				flag++;
			j++;
		}
		i++;
	}
	if (flag != 1)
		display_errors2(606);
}
