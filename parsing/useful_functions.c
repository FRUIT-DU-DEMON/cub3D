/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 00:24:48 by hlabouit          #+#    #+#             */
/*   Updated: 2024/01/02 04:44:29 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"parsing.h"

char	**join_map_code(int fd)
{
	char	**map_code;
	char	*mc_1d;
	char	buf[2];
	int		i;
	int		j;

	i = read(fd, buf, 1);
	if (i == 0)
		display_errors(202);
	j = 0;
	buf[i] = 0;
	mc_1d = ft_strdup_prs("");
	while (i)
	{
		mc_1d = ft_strjoin_prs(mc_1d, buf);
		i = read(fd, buf, 1);
		buf[i] = 0;
	}
	map_code = ft_split_prs(mc_1d, '\n');
	return (free(mc_1d), map_code);
}


