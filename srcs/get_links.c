/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_links.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 13:38:59 by gduval            #+#    #+#             */
/*   Updated: 2017/05/04 13:39:00 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static char ***create_array(int count)
{
    int     i;
    char    ***array;

    i = -1;
    array = NULL;
    if (!(array = (char ***)ft_memalloc(sizeof(char **) * (count + 1))))
        error();
    array[count] = NULL;
    while (++i < count)
    {
        if (!(array[i] = (char **)ft_memalloc(sizeof(char *) * 3)))
            error();
        array[i][2] = NULL;
    }
    return (array)
}

static char ***get_links_array(char **old_array, int count)
{
    int     i;
    int     mid;
    char    ***new_array;

    i = -1;
    mid = 0;
    new_array = create_array(count);
    while (++i < count)
    {
        if (!check_string(old_array[i]))
            error();
        mid = ft_strchr(old_array[i], '-');
        new_array[i][0] = ft_strsub(old_array[i], 0, mid);
        new_array[i][1] = ft_strsub(old_array[i], mid + 1, \
            ft_strlen(old_array[i] - mid));
    }
    // delete old array
    return (new_array);
}

static int  get_lst_links(char **tmp_links)
{
    char    *line;
    int     count;

    line = NULL;
    count = 0;
    while (get_next_line(0, &line) > 0)
    {
        if (line[0] != '#' && line[0] != 'L')
        {
            line = ft_strjoin_clean(line, " ", 1);
            if (*tmp_links)
                *tmp_links = ft_strjoin_clean(*tmp_links, line, 1);
            else
                *tmp_links = ft_strdup(line);
            count++;
        }
        ft_strdel(&line);
    }
    ft_strdel(&line);
    return (count);
}

int         get_links(char *first_link, t_global *global)
{
    char    *tmp_links;
    char    **tmp_links_array;
    int     count;

    tmp_links = NULL;
    tmp_links_array = NULL;
    count = 0;
    if (first_link[0] != '#' && first_link[0] != 'L')
        tmp_links = ft_strjoin(first_link, " ")
    count = get_lst_links(&tmp_links);
    tmp_links_array = ft_strsplit(tmp_links, ' ');
    global->links = get_links_array(count, tmp_links_array);
    ft_strdel(&first_link);
    return (0);
}
