/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bslakey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 20:17:37 by bslakey           #+#    #+#             */
/*   Updated: 2016/10/18 00:44:40 by bslakey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include "stdio.h"

# define BUFF_SIZE 21
# define TYPE_PARSE(x) (tet_map[r + (x[0])][c + (x[1])])
# define ERR_GUARD(x, y) if (x) return (y)
# define VAR5_INIT0(a, b, c, d, e) int a = 0, b = 0, c = 0, d = 0, e = 0;

typedef struct		s_tet
{
	char			**tet_grid;
	int				**type;
	int				height;
	int				width;
	char			letter;
	struct s_tet	*next;
}					t_tet;

char				*tet_file_read(const char *file_name);
char				**tet_map_piece(char const *s, char c);
t_tet				*tet_lst_map(char *tet_file, int num_tets);
int					tet_piece_chk(char **tet_grid);
int					tet_file_chk(char *file_content, int *num_tets);
void				tet_place(t_tet *node, char **map, int cr, char w);
int					attempt_place(t_tet *tet, char **tet_map, int c, int r);
char				**tet_solver(t_tet **head, int list_length);
void				tet_print_usage(void);
void				tet_print_err(void);
#endif
