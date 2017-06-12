/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tet_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bslakey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 06:11:37 by bslakey           #+#    #+#             */
/*   Updated: 2016/10/24 20:09:57 by bslakey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <stdio.h>

static void		print_solution(char **map)
{
	int i;
	int j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			write(1, &map[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int				main(int argc, char **argv)
{
	int		num_tets;
	char	*tet_file;
	t_tet	*curr_node;
	char	**solution;

	num_tets = 0;
	if (argc == 2)
	{
		tet_file = tet_file_read(argv[1]);
		if (tet_file_chk(tet_file, &num_tets) < 1)
			return (0);
		if ((curr_node = tet_lst_map(tet_file, num_tets)) == NULL)
		{
			tet_print_err();
			return (0);
		}
		solution = tet_solver(&curr_node, num_tets);
		print_solution(solution);
		free(solution);
	}
	else
		tet_print_usage();
	return (0);
}
