/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvievill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 18:34:00 by rvievill          #+#    #+#             */
/*   Updated: 2017/04/03 18:34:01 by rvievill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putmap(char **c)
{
	int y;

	if (!c)
		return ;
	y = 0;
	while (c[y])
	{
		ft_putstr(c[y]);
		ft_putchar('\n');
		ft_putendl("--------------------");
		y++;
	}
}