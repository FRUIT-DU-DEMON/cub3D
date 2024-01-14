/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_errors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 20:24:45 by hlabouit          #+#    #+#             */
/*   Updated: 2024/01/14 03:33:02 by hlabouit         ###   ########.fr       */
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
		printf("Error\nmap file is empty!\n");
		exit(EXIT_FAILURE);
	}
	if (signal == 303)
	{
		printf("Error\ninvalid number of arguments!\n");
		exit(EXIT_FAILURE);
	}
	if (signal == 404)
	{
		printf("Error\nfailed to open map file!\n");
		exit(EXIT_FAILURE);
	}
	if (signal == 505)
	{
		printf("Error\ninvalid map characters!\n");
		exit(EXIT_FAILURE);
	}
}

void	display_errors2(int signal)
{
	if (signal == 606)
	{
		printf("Error\nmap countains more than one start position!\n");
		exit(EXIT_FAILURE);
	}
	if (signal == 707)
	{
		printf("Error\nmap isn't surrounded by walls!\n");
		exit(EXIT_FAILURE);
	}
	if (signal == 808)
	{
		printf("Error\nmap countains empty lines!\n");
		exit(EXIT_FAILURE);
	}
	if (signal == 909)
	{
		printf("Error\nmap countains duplicated elements element!\n");
		exit(EXIT_FAILURE);
	}
	if (signal == -101)
	{
		printf("Error\nmap must countain 6 valid elements at the top of .cub file !\n");
		exit(EXIT_FAILURE);
	}
}
void	display_errors3(int signal)
{
	if (signal == -202)
	{
		printf("Error\ninvalid elemnts!\n");
		exit(EXIT_FAILURE);
	}
	if (signal == 479)
	{
		printf("Error\nmap elements must be the first in .cub file!\n");
		exit(EXIT_FAILURE);
	}
	// if (signal == 666)
	// {
	// 	printf("Error\nfloor and ceiling colors range must be in this form : [0,255],[0,255],[0,255]!\n");
	// 	exit(EXIT_FAILURE);
	// }
	
}
