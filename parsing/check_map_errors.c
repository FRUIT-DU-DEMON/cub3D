/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 04:36:06 by hlabouit          #+#    #+#             */
/*   Updated: 2024/01/02 04:46:02 by hlabouit         ###   ########.fr       */
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

