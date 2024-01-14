/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 01:20:11 by hlabouit          #+#    #+#             */
/*   Updated: 2024/01/14 09:25:46 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"parsing.h"

// void parsing(char **map_content, char **virtual_map, char *mc_1d)
// {
	
// }

int main(int ac, char **av)
{
	char **map_content;
	char *mc_1d;
	char **map_code;//here's the returned map code
	char **virtual_map;
	int fd;
	t_dimention dmt;
	int i = 0;
	
	if (ac < 2)
		display_errors(303);
	check_map_extension(av);
	fd = open(av[1], O_CREAT | O_RDONLY);
	if (fd == -1)
		display_errors(404);
	mc_1d = join_map_content(fd);
	map_content = ft_split_prs(mc_1d, '\n');

	virtual_map = create_virtual_map(map_content);
	dmt = check_map_elements(map_content, mc_1d);
	map_code = malloc((dmt.lines - dmt.i + 1) * sizeof(char *));
	map_code[dmt.lines - dmt.i] = NULL;
	check_map_characters(map_content, dmt);
	check_map_4sides_wall(virtual_map, dmt);
	check_map_wall(virtual_map, dmt);	
	while(virtual_map[dmt.i])
		map_code[i++] = virtual_map[dmt.i++];
	// your map_code that you are gonna use is this !!!! upupup
	while (*map_code)
		printf("[%s]\n", *map_code++);
}