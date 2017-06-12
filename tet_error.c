/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tet_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bslakey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 06:46:06 by bslakey           #+#    #+#             */
/*   Updated: 2016/10/10 07:00:07 by bslakey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	tet_print_usage(void)
{
	ft_putstr_fd("./fillit source_file\n", 1);
}

void	tet_print_err(void)
{
	ft_putstr_fd("error\n", 1);
}
