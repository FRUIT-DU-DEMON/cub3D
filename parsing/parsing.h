/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 00:19:54 by hlabouit          #+#    #+#             */
/*   Updated: 2023/12/22 20:57:17 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

#include<libc.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>
# include <fcntl.h>


///////// libft //////////
int		ft_strlen_prs(char *s);
size_t	ft_strlcpy_prs(char *dst, char *src, size_t dstsize);
char	*ft_strjoin_prs(char *s1, char *s2);
char	**ft_split_prs(char *s, char c);
char	*ft_strdup_prs(char *s1);
///////// libft //////////



void	display_errors(int signal);

#endif