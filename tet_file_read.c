/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bslakey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 13:53:01 by bslakey           #+#    #+#             */
/*   Updated: 2016/10/22 13:40:54 by bslakey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <stdio.h>

char		*tet_file_read(const char *file_name)
{
	size_t	curr_size;
	char	*text;
	char	buffer[BUFF_SIZE];

	VAR4_INIT0(fd, ret, i , n_reads)
	if((fd = open(file_name, O_RDONLY)) == -1)
		return (NULL);
	while ((ret = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		i = -1;
		curr_size = (BUFF_SIZE * n_reads);
		if (ret == -1)
			return (NULL);
		if(n_reads)
			text = ft_realloc(text, curr_size, (curr_size + ret + 1));
		else
			text = ft_strnew(BUFF_SIZE + 1);
		while (++i < ret)
			text[(curr_size) + i] = buffer[i];
		n_reads++;
	}
	return (text);
}
