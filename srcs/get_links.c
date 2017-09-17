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

static void		insert_links(t_links **link, char **line)
{
	short int	i;

	i = (short int)ft_strchri(*line, '-');
	(*link)->link_a = ft_strsub(*line, 0, (size_t)i);
	(*link)->link_b = ft_strsub(*line, (unsigned int)i + 1, ft_strlen(*line) - (size_t)i);
}

static void		implement_first_link(t_links **tmp, char **line)
{
	if (ft_strchri(*line, '-'))
	{
		insert_links(tmp, line);
		(*tmp)->next = init_link();
		(*tmp) = (*tmp)->next;
	}
	ft_strdel(line);
}

void			get_links(char **line, t_dna *dna)
{
	t_links		*link;
	t_links		*tmp;

	link = init_link();
	tmp = link;
	implement_first_link(&tmp, line);
	while (get_next_line(0, line) > 0)
	{
		if (*line[0] == 'L')
			break ;
		if (ft_strchri(*line, '-'))
		{
			insert_links(&tmp, line);
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
