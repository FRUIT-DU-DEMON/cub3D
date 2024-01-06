/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 04:36:06 by hlabouit          #+#    #+#             */
/*   Updated: 2024/01/06 23:40:20 by hlabouit         ###   ########.fr       */
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
	t_dimention dmt;

	dmt.flag = 0;
	dmt.i = 0;
	while (map_code[dmt.i])
	{
		dmt.j = 0;
		while (map_code[dmt.i][dmt.j])
		{
			if (map_code[dmt.i][dmt.j] != '0' && map_code[dmt.i][dmt.j] != '1'
				&& map_code[dmt.i][dmt.j] != 'N' && map_code[dmt.i][dmt.j] != 'S'
				&& map_code[dmt.i][dmt.j] != 'E' && map_code[dmt.i][dmt.j] != 'W'
				&& map_code[dmt.i][dmt.j] != ' ')
					display_errors(505);
			if (map_code[dmt.i][dmt.j] =='N' || map_code[dmt.i][dmt.j] =='S'
				|| map_code[dmt.i][dmt.j] =='E' || map_code[dmt.i][dmt.j] =='W')
					dmt.flag++;
			dmt.j++;
		}
		dmt.i++;
	}
	if (dmt.flag != 1)
		display_errors2(606);
}

// char get_start_point(char **map_code)
// {
// 	int	i;
// 	int	j;
// 	char start_point;

// 	i = 0;
// 	while (map_code[i])
// 	{
// 		j = 0;
// 		while (map_code[i][j])
// 		{
// 			if (map_code[i][j] == 'N' || map_code[i][j] == 'S'
// 				|| map_code[i][j] == 'E' || map_code[i][j] == 'W')
// 			{
// 				start_point = map_code[i][j]; 
// 				return (start_point);
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (0);
// }


t_dimention	get_mc_dimentios(char **map_code)
{
	t_dimention dmt;

	dmt.i = 0;
	dmt.longest_line = 0;
	while (map_code[dmt.i])
	{
		dmt.j = 0;
		while (map_code[dmt.i][dmt.j])
			dmt.j++;
		if (dmt.j > dmt.longest_line)
			dmt.longest_line = dmt.j;
		dmt.i++;
	}
	dmt.lines = dmt.i;
	return (dmt);
}

char	**create_virtual_map(char **map_code)
{
	t_dimention dmt;
	char **virtual_map;
	
	dmt = get_mc_dimentios(map_code);
	dmt.i = 0;
	virtual_map = malloc((dmt.lines + 1) * sizeof(char *));
	virtual_map[dmt.lines] = NULL;
	dmt.lines--;
	while (dmt.lines >= 0)
	{
		virtual_map[dmt.lines] = malloc((dmt.longest_line + 1) * sizeof(char));
		dmt.lines--;
	}
	while (map_code[dmt.i])
	{
		dmt.j = 0;
		while (map_code[dmt.i][dmt.j])
		{
			virtual_map[dmt.i][dmt.j] = map_code[dmt.i][dmt.j];
			dmt.j++;
		}
		virtual_map[dmt.i][dmt.longest_line] = '\0';
		while (dmt.j < dmt.longest_line)
		{
			virtual_map[dmt.i][dmt.j] = ' ';
			dmt.j++;
		}
		dmt.i++;
	}
	while (*virtual_map)//vmap
		printf("[%s]\n", *virtual_map++);
	// exit(0);
	return (virtual_map);
}

void	check_map_wall(char **map_code)
{
	t_dimention dmt;

	dmt = get_mc_dimentios(map_code);
	dmt.flag = 0;
	dmt.i = 1;
	while (map_code[dmt.i])
	{
		dmt.j = 0;
		while (map_code[dmt.i][dmt.j])
		{
			if (map_code[dmt.i][dmt.j] == '0' && (map_code[dmt.i + 1][dmt.j] == ' ' || map_code[dmt.i - 1][dmt.j] == ' '
				|| map_code[dmt.i][dmt.j + 1] == ' ' || map_code[dmt.i][dmt.j - 1] == ' '))
					display_errors2(707);
			dmt.j++;
		}
		dmt.i++;
	}

}
