/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_errors2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 22:24:07 by hlabouit          #+#    #+#             */
/*   Updated: 2024/01/08 04:49:56 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"parsing.h"

void    check_map_elements(char **map_code)
{
    t_dimention dmt;
    t_elements elmt;

    dmt = get_mc_dimentios(map_code);
    elmt.no_path = NULL;
    elmt.so_path = NULL;
    elmt.we_path = NULL;
    elmt.ea_path = NULL;
    elmt.floor_color = NULL;
    elmt.ceiling_color = NULL;
    dmt.i = 0;
    dmt.j = 0;
    while (map_code[dmt.i][0] == '\n')
        dmt.i++;
    while (map_code[dmt.i])
    {
        dmt.j = 0;
        while (map_code[dmt.i][dmt.j] == ' ')
            dmt.j++;
            elmt.no_path = *(map_code + dmt.j);
            printf("[%s]\n", elmt.no_path);
        if ((map_code[dmt.i][dmt.j] == 'N' && map_code[dmt.i][dmt.j + 1] == 'O')
            || (map_code[dmt.i][dmt.j] == 'S' && map_code[dmt.i][dmt.j + 1] == 'O')
            || (map_code[dmt.i][dmt.j] == 'W' && map_code[dmt.i][dmt.j + 1] == 'E')
            || (map_code[dmt.i][dmt.j] == 'E' && map_code[dmt.i][dmt.j + 1] == 'A'))
        {
            dmt.j += 2;
            while (map_code[dmt.i][dmt.j] != ' ')
                dmt.j++;
            exit(0);
        }
    }
    
}
