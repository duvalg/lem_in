/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_links.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 17:02:37 by gduval            #+#    #+#             */
/*   Updated: 2017/09/05 17:02:38 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int		check_links(t_links **link, char **line, int separate, t_dna *dna)
{
	char		*link_a_tmp;
	char		*link_b_tmp;

	if (!(link_a_tmp = ft_strsub(*line, 0, separate)))
		error();
	if (!find_room_by_name(&link_a_tmp, dna))
	{
		ft_strdel(&link_a_tmp);
		return (0);
	}
	if (!(link_b_tmp = ft_strsub(*line, separate + 1, ft_strlen(*line) - \
	(size_t)separate)))
		error();
	if (!find_room_by_name(&link_b_tmp, dna))
	{
		ft_strdel(&link_a_tmp);
		ft_strdel(&link_b_tmp);
		return (0);
	}
	else
	{
		(*link)->link_a = link_a_tmp;
		(*link)->link_b = link_b_tmp;
	}
	return (1);
}

static int		insert_links(t_links **link, char **line, t_dna *dna)
{
	int			i;

	i = -1;
	while (++i < ft_strlen(*line))
	{
		if (check_links(link, line, i, dna))
			return (1);
	}
	return (0);
}

static void		implement_first_link(t_links **tmp, char **line, t_dna *dna)
{
		if (!insert_links(tmp, line, dna))
			error();
		(*tmp)->next = init_link();
		(*tmp) = (*tmp)->next;
		ft_putendl(*line);
		ft_strdel(line);
}

void			get_links(char **line, t_dna *dna)
{
	t_links		*link;
	t_links		*tmp;

	link = init_link();
	tmp = link;
	implement_first_link(&tmp, line, dna);
	while (get_next_line(0, line) > 0)
	{
		if (*line[0] == 'L' || !ft_strchr(*line, '-'))
			break ;
		else if (ft_strchri(*line, '-') && *line[0] != '#')
		{
			if (!insert_links(&tmp, line, dna))
				break ;
			tmp->next = init_link();
			tmp = tmp->next;
		}
		ft_putendl((const char *)*line);
		ft_strdel(line);
	}
	ft_strdel(line);
	write(1, "\n", 1);
	dna->links = link;
	set_index(dna);
}
