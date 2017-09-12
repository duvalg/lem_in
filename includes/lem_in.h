/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 11:20:37 by gduval            #+#    #+#             */
/*   Updated: 2017/09/05 11:20:39 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/includes/libft.h"

typedef struct		s_room
{
	char			*name;
	int				index;
	int				active;
}					t_room;

typedef struct		s_links
{
	char			*link_a;
	char			*link_b;
	struct s_links	*next;
}					t_links;

typedef struct		s_dna
{
	int				ants;
	int				rooms_nb;
	int				keyrooms[2];
	char			**room_lst;
	t_room			*rooms;
	t_links			*links;
}					t_dna;

int					main(void);
t_dna				init_dna(void);
t_links				*init_link(void);
void				parse(t_dna	*dna)__attribute__ ((noreturn));
void				create_rooms(char **line, t_dna *dna)\
__attribute__ ((noreturn));
void				get_links(char **line, t_dna *dna)\
__attribute__ ((noreturn));
void				set_index(t_dna *dna)\
__attribute__ ((noreturn));
void				error(void)__attribute__ ((noreturn));
void				ft_exit(t_dna *dna)__attribute__ ((noreturn));

#endif
