/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_errors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 20:24:45 by hlabouit          #+#    #+#             */
/*   Updated: 2023/12/22 20:55:45 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"parsing.h"

void	display_errors(int signal)
{
	if (signal == 404)
	{
		printf("Error\nlack of args\n");
		exit(EXIT_FAILURE);
	}
	if (signal == 0)
	{
		printf("Error\nunvalide map file extension\n");
		exit(EXIT_FAILURE);
	}
	if (signal == 1)
	{
		printf("Error\nmap.ber file is empty\n");
		exit(EXIT_FAILURE);
	}
	if (signal == 2)
	{
		printf("Error\nmap countains empty lines\n");
		exit(EXIT_FAILURE);
	}
}