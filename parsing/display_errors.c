/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_errors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 20:24:45 by hlabouit          #+#    #+#             */
/*   Updated: 2024/01/02 03:23:11 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"parsing.h"

void	display_errors(int signal)
{
	if (signal == 101)
	{
		printf("Error\ninvalid map file extension!\n");
		exit(EXIT_FAILURE);
	}
	if (signal == 202)
	{
		printf("Error\nmap.cub file is empty!\n");
		exit(EXIT_FAILURE);
	}
	if (signal == 303)
	{
		printf("Error\ninvalid number of arguments!\n");
		exit(EXIT_FAILURE);
	}
	if (signal == 404)
	{
		printf("Error\nfailed to open map.cub file!\n");
		exit(EXIT_FAILURE);
	}
}
