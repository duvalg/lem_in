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

static void	insert_key_room(int index, int *keyroom, t_dna *dna)
{
	if (*keyroom == 1)
	{
		if (dna->keyrooms[0] == -1)
			dna->keyrooms[0] = index;
		else
			error();
	}
	else if (*keyroom == 2)
	{
		if (dna->keyrooms[1] == -1)
			dna->keyrooms[1] = index;
		else
			error();
	}
	*keyroom = 0;
}

static int	room_is_viable(char **line)
{
	int		i;
	int		j;
	int		start;
	int		coord;

	i = ft_strchri(*line, ' ');
	start = i;
	coord = 0;
	while ((*line)[++i])
	{
		if (((*line)[i] < '0' || (*line)[i] > '9') && (*line)[i] != ' ')
			error();
		if ((*line)[i] >= '0' && (*line)[i] <= '9')
		{
			coord++;
			j = i - 1;
			while ((*line)[++j] >= '0' && (*line)[j] <= '9')
				if (j - i >= 6)
					error();
			i = j - 1;
		}
	}
	if (i == start + 1 || coord != 2)
		error();
	return (1);
}

static void	data_processing(char **lst, char **line, int *keyroom, t_dna *dna)
{
	char	*name;

	name = NULL;
	if (!room_is_viable(line))
		error();
	if (ft_strchr(*line, '-'))
		error();
	if (!(name = ft_strsub(*line, 0, ft_strchri(*line, ' ') + 1)))
		error();
	else if (ft_strlen(name) > 1000 || name[0] == 'L')
		error();
	else if (!(*lst = (!*lst) ? name : ft_strjoin_free(*lst, name, 3)))
		error();
	insert_key_room(dna->rooms_nb, keyroom, dna);
	++(dna->rooms_nb);
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
		if (!ft_strlen(*line))
			error();
		if (*line[0] != '#' && !ft_strchr(*line, ' '))
			break ;
		else if (!ft_strcmp("##start", *line) || !ft_strcmp("##end", *line))
			keyroom = (!ft_strcmp("##end", *line)) ? 2 : 1;
		else if (*line[0] != '#')
			data_processing(&lst, line, &keyroom, dna);
		ft_putendl((const char *)*line);
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
	if (dna->keyrooms[0] < 0 || dna->keyrooms[1] < 0)
		error();
	if (dna->keyrooms[0] == dna->keyrooms[1])
		error();
	if (!(dna->room_lst = ft_strsplit(*room_lst, ' ')))
		error();
	ft_strdel(room_lst);
	create_rooms(&line, dna);
}
