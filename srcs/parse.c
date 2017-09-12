/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 12:17:15 by gduval            #+#    #+#             */
/*   Updated: 2017/09/05 12:17:16 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int	get_ants(t_dna *dna, char **line)
{
	unsigned short	ants;
	unsigned short	ret;

	ants = 0;
	while ((ret = (unsigned short)get_next_line(0, line)) > 0)
	{
		if ((ants = (unsigned short)ft_atoi(*line)) != 0)
			break ;
	}
	if (ret < 0 || ants <= 0)
	{
		if (*line)
			ft_strdel(line);
		error();
	}
	dna->ants = ft_atoi(*line);
	ft_strdel(line);
	return (0);
}

static void	insert_key_room(int index, int *keyroom, t_dna *dna)
{
	if (*keyroom == 1)
	{
		if (dna->keyrooms[0] == 0)
			dna->keyrooms[0] = index;
		else
			error();
	}
	else if (*keyroom == 2)
	{
		if (dna->keyrooms[1] == 0)
			dna->keyrooms[1] = index;
		else
			error();
	}
	*keyroom = 0;
}

static char	**get_rooms(t_dna *dna, char **line)
{
	int			keyroom;
	char		*name;
	static char	*lst = NULL;

	name = NULL;
	keyroom = 0;
	while (get_next_line(0, line))
	{
		if (*line[0] != '#' && !ft_strchr(*line, ' '))
			break ;
		else if (!ft_strcmp("##start", *line) || !ft_strcmp("##end", *line))
			keyroom = (!ft_strcmp("##end", *line)) ? 2 : 1;
		else
		{
			if (*line[0] != '#')
			{
				name = ft_strsub(*line, 0, (size_t)ft_strchri(*line, ' ') + 1);
				lst = (!lst) ? name : ft_strjoin_free(lst, name, 3);
				insert_key_room(dna->rooms_nb, &keyroom, dna);
				++(dna->rooms_nb);
			}
		}
		ft_strdel(line);
	}
	return ((char **)&lst);
}

void		parse(t_dna *dna)
{
	char	*line;
	char	**room_lst;

	line = NULL;
	room_lst = NULL;
	get_ants(dna, &line);
	room_lst = get_rooms(dna, &line);
	dna->room_lst = ft_strsplit(*room_lst, ' ');
	ft_strdel(room_lst);
	create_rooms(&line, dna);
}
