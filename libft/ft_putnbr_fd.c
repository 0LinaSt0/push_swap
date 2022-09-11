/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalena <msalena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 21:09:53 by msalena           #+#    #+#             */
/*   Updated: 2021/08/20 21:09:54 by msalena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_write(char *d, int fd, int i)
{
	while (i <= 10)
	{
		write(fd, &d[i], 1);
		i++;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	char		xg[11];
	size_t		i;
	long int	p;

	i = 10;
	p = n;
	if (p == 0)
	{
		xg[i] = '0';
		ft_write(xg, fd, 10);
		return ;
	}
	if (p < 0)
		p *= -1;
	while (p > 0)
	{
		xg[i--] = p % 10 + '0';
		p = p / 10;
	}
	i++;
	if (n < 0)
		xg[--i] = '-';
	ft_write(xg, fd, i);
}
