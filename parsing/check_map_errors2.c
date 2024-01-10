/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_errors2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 22:24:07 by hlabouit          #+#    #+#             */
/*   Updated: 2024/01/10 04:57:05 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"parsing.h"


void set_element_data(char *texture_path, t_elements *elmt, char identifier)
{
    
    if (identifier == 'N')
    {
        if (elmt->no_path != NULL)
            display_errors2(909);
        elmt->no_path = texture_path;
    }
    else if (identifier == 'S')
    {
        if (elmt->so_path != NULL)
            display_errors2(909);
        elmt->so_path = texture_path;
    }
    else if (identifier == 'W')
    {
        if (elmt->we_path != NULL)
            display_errors2(909);
        elmt->we_path = texture_path;
    }
    else if (identifier == 'E')
    {
        if (elmt->ea_path != NULL)
            display_errors2(909);
        elmt->ea_path = texture_path;
    }
    else if (identifier == 'F')
    {
        if (elmt->floor_color != NULL)
            display_errors2(909);
        elmt->floor_color = texture_path;
    }
    else if (identifier == 'C')
    {
        if (elmt->ceiling_color != NULL)
            display_errors2(909);
        elmt->ceiling_color = texture_path;
    }
}

void which_element(t_elements *elmt, t_dimention *dmt, int space_index)
{
    if (elmt->tmp[dmt->j + space_index] == ' ')
    {
        dmt->j += space_index;
        while (elmt->tmp[dmt->j] == ' ')
            dmt->j++;
        elmt->tmp = elmt->tmp + dmt->j;
        while (elmt->tmp[dmt->j] != '\0')
            dmt->j++;
        dmt->j--;
        while (elmt->tmp[dmt->j] == ' ')
            dmt->j--;
        elmt->tmp[dmt->j + 1] = '\0';
    }
}


t_elements  check_map_elements(char **map_code)
{
    t_dimention dmt;
    t_elements elmt;
    char identifier;

    elmt.no_path = NULL;
    elmt.so_path = NULL;
    elmt.we_path = NULL;
    elmt.ea_path = NULL;
    elmt.floor_color = NULL;
    elmt.ceiling_color = NULL;
    dmt = get_mc_dimentios(map_code);
    elmt.tmp = NULL;
    dmt.i = 0;
    dmt.j = 0;
    while (map_code[dmt.i])
    {
        dmt.j = 0;
        elmt.tmp = map_code[dmt.i];
        while(elmt.tmp[dmt.j])
        {
            if (elmt.tmp[dmt.j] == get_start_point(map_code) && (elmt.tmp[dmt.j + 1] == '1' || elmt.tmp[dmt.j + 1] == '0')) //Must check here if one of ptrs is NULL
                display_errors3(479);
            dmt.j++;
        }
        dmt.j = 0;
        while (elmt.tmp[dmt.j] == ' ')
            dmt.j++;
        if ((elmt.tmp[dmt.j] == 'N' && elmt.tmp[dmt.j + 1] == 'O')
            || (elmt.tmp[dmt.j] == 'S' && elmt.tmp[dmt.j + 1] == 'O')
            || (elmt.tmp[dmt.j] == 'W' && elmt.tmp[dmt.j + 1] == 'E')
            || (elmt.tmp[dmt.j] == 'E' && elmt.tmp[dmt.j + 1] == 'A')
            || (elmt.tmp[dmt.j] == 'F' && elmt.tmp[dmt.j + 1] == ' ')
            || (elmt.tmp[dmt.j] == 'C' && elmt.tmp[dmt.j + 1] == ' '))
        {
            identifier = elmt.tmp[dmt.j];
            if (elmt.tmp[dmt.j + 2] == ' ')
            {
                which_element(&elmt, &dmt, 2);
                set_element_data(elmt.tmp, &elmt, identifier);
            }
            else if (elmt.tmp[dmt.j + 1] == ' ')
            {
                which_element(&elmt, &dmt, 1);
                set_element_data(elmt.tmp, &elmt, identifier);
            }
        }
        dmt.i++;
    }
    return(elmt);
    // printf("[%s]\n", elmt.no_path);
    // printf("[%s]\n", elmt.so_path);
    // printf("[%s]\n", elmt.we_path);
    // printf("[%s]\n", elmt.ea_path);
    // printf("[%s]\n", elmt.floor_color);
    // printf("[%s]\n", elmt.ceiling_color);
    // exit(0);
}
