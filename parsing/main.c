/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 01:20:11 by hlabouit          #+#    #+#             */
/*   Updated: 2023/12/21 19:33:10 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<libc.h>


//.cub
void	check_map_extension(char **av)
{
	int j;

	j = 0;
	while (av[1][j])
		j++;
	if (av[1][j - 1] == 'b' && av[1][j - 2] == 'u' && av[1][j - 3] == 'c' && av[1][j - 4] == '.')
		return;
	else
	{
		printf("ERROR: invalid map extention\n");
		exit(1);
	}
}



int main(int ac, char **av)
{
	if (ac != 2)
	{
		printf("ERROR: invalid number of arguments\n");
		exit(1);
	}
	check_map_extension(av);
}