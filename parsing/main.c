/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 01:20:11 by hlabouit          #+#    #+#             */
/*   Updated: 2024/01/05 03:45:44 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"parsing.h"


int main(int ac, char **av)
{
	if (ac < 2)
		display_errors(303);
	check_map_extension(av);
	int fd = open(av[1], O_CREAT | O_RDONLY);
	if (fd == -1)
		display_errors(404);
	char **mc = join_map_code(fd);
	check_map_characters(mc);
	check_map_wall(mc);
	printf("CLEEANNN MAP\n");
	// while (*mc)
	// 	printf("%s\n", *mc++);
}