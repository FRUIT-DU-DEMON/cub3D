/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 01:20:11 by hlabouit          #+#    #+#             */
/*   Updated: 2023/12/22 20:56:19 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"parsing.h"

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

char	**join_map_code(int fd)
{
	char	**map_code;
	char	*mc_1d;
	char	buf[2];
	int		i;
	int		j;

	i = read(fd, buf, 1);
	if (i == 0)
		display_errors(1);
	j = 0;
	buf[i] = 0;
	mc_1d = ft_strdup_prs("");
	while (i)
	{
		mc_1d = ft_strjoin_prs(mc_1d, buf);
		i = read(fd, buf, 1);
		buf[i] = 0;
		if (mc_1d[0] == '\n'
			|| (mc_1d[ft_strlen_prs(mc_1d) - 1] == '\n' && buf[0] == '\n'))
			display_errors(2);
	}
	if (mc_1d[ft_strlen_prs(mc_1d) - 1] == '\n')
		display_errors(2);
	map_code = ft_split_prs(mc_1d, '\n');
	return (free(mc_1d), map_code);
}



int main(int ac, char **av)
{
	if (ac != 2)
		display_errors(404);
	check_map_extension(av);
	int fd = open(av[1], O_RDONLY);
	join_map_code(fd);
}