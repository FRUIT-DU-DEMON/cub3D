/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 01:20:11 by hlabouit          #+#    #+#             */
/*   Updated: 2024/01/14 05:21:08 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"parsing.h"

void parsing(char **map_code, char **virtual_map, char *mc_1d)
{
	t_dimention dmt;
	
	dmt = check_map_elements(map_code, mc_1d);
	check_map_characters(map_code, dmt);
	check_map_4sides_wall(virtual_map, dmt);
	check_map_wall(virtual_map, dmt);	
}

int main(int ac, char **av)
{
	char **map_code;
	char *mc_1d;
	char **virtual_map;
	int fd;
	
	if (ac < 2)
		display_errors(303);
	check_map_extension(av);
	fd = open(av[1], O_CREAT | O_RDONLY);
	if (fd == -1)
		display_errors(404);
	mc_1d = join_map_code(fd);
	map_code = ft_split_prs(mc_1d, '\n');

	virtual_map = create_virtual_map(map_code);
	parsing(map_code, virtual_map, mc_1d);
	// check_map_elements(map_code, mc_1d);
	// check_map_elements(map_code);
	// printf("\n---------------------------------------------------------------------\n");
	// while (*map_code)//map
	// 	printf("[%s]\n", *map_code++);
}