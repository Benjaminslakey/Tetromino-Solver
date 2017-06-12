/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bslakey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 04:19:30 by bslakey           #+#    #+#             */
/*   Updated: 2016/10/24 21:35:02 by bslakey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

static int		tet_chk_connect(char **tet_grid, int row, int col)
{
	int		connections;

	connections = 0;
	if (col != 0 && tet_grid[row][col - 1] == '#')
		connections++;
	if (col != 4  && tet_grid[row][col + 1] == '#')
		connections++;
	if (row != 0 && tet_grid[row - 1][col] == '#')
		connections++;
	if (row != 3 && tet_grid[row + 1][col] == '#')
		connections++;
	return (connections);
}

static int		tet_line_chk(char **tet_grid, int *hashes, int line, int *c_sum)
{
	int	i;

	i = 0;
	while (tet_grid[line][i] != '\n')
	{
		if (tet_grid[line][i] == '#' || tet_grid[line][i] == '.')
		{
			if (tet_grid[line][i] == '#')
			{
				(*hashes)++;
				if(tet_chk_connect(tet_grid, line, i) > 0)
					*c_sum += tet_chk_connect(tet_grid, line, i);
				else
					return (-1);
			}
			i++;
		}
		else
			return (0);
	}
	return (1);
}

int			tet_piece_chk(char **tet_grid)
{
	int	i;
	int	hashes;
	int c_sum;

	i = 0;
	hashes = 0;
	c_sum = 0;
	while (tet_grid[i] && ft_strlen(tet_grid[i]) == 5)
	{
		ERR_GUARD(((tet_line_chk(tet_grid, &hashes, i, &c_sum)) == -1), 0);
		i++;
	}
	if (c_sum == 6 || c_sum == 8)
		return (1);
	else
		return (0);
}

int			tet_file_chk(char *file_content, int *num_tets)
{
	VAR5_INIT0(i, hashes, dots, newlines, tets)
	while (file_content[i])
	{
		if (file_content[i] == '#')
			hashes++;
		else if (file_content[i] == '.')
			dots++;
		else if (file_content[i] == '\n')
			newlines++;
		i++;
	}
	if (((hashes % 4) == 0) && (hashes * 3) == dots)
		tets = (hashes/4);
	if ((newlines + 1) == (tets * 5))
		;
	else
	{
		tet_print_err();
		return (0);
	}
	ERR_GUARD((tets > 26), 0);
	(*num_tets) += tets;
	return (1);
}
