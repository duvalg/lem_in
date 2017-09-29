/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 14:15:59 by gduval            #+#    #+#             */
/*   Updated: 2017/09/08 14:16:02 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void		free_rooms(t_dna *dna)
{
	int			i;

	i = -1;
	while (++i < dna->rooms_nb)
	{
		if (dna->rooms[i].name)
			ft_strdel(&dna->rooms[i].name);
	}
}

static void		free_links(t_dna *dna)
{
	t_links		*tmp;
	t_links		*tmp_dup;

	tmp = dna->links;
	while (tmp->next)
	{
		ft_strdel(&(tmp->link_a));
		ft_strdel(&(tmp->link_b));
		tmp_dup = tmp->next;
		ft_memdel((void **)&tmp);
		tmp = tmp_dup;
		tmp_dup = NULL;
	}
	ft_memdel((void **)&tmp);
}

void			ft_exit(t_dna *dna)
{
	int			i;

	i = -1;
	while (++i < dna->rooms_nb)
		ft_memdel((void **)&(dna->rooms[i]));
	free_links(dna);
	free_rooms(dna);
	i = -1;
	ft_memdel((void **)&dna->room_lst);
	exit(EXIT_SUCCESS);
}

void			error(void)
{
	write(2, "ERROR\n", 6);
	exit(EXIT_FAILURE);
}
