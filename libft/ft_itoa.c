/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalena <msalena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 21:08:45 by msalena           #+#    #+#             */
/*   Updated: 2021/08/20 21:08:46 by msalena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_rev_for_null(char *r)
{
	char	temp;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(r);
	while (i < len / 2)
	{
		temp = r[i];
		r[i] = r[len - i - 1];
		r[len - i++ - 1] = temp;
	}
}

static void	*ft_rev(char *r)
{
	char	temp;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(r);
	if (r[0] == '-')
	{
		i = 1;
		len--;
		while (i <= len / 2)
		{
			temp = r[i];
			r[i] = r[len - (i - 1)];
			r[len - (i++ - 1)] = temp;
		}
	}
	else
		ft_rev_for_null(r);
	return (r);
}

static int	ft_count(long int c)
{
	size_t		ct;

	ct = 1;
	if (c < 0)
		ct++;
	if (c < 0)
		c *= -1;
	while (c >= 10)
	{
		c = c / 10;
		ct++;
	}
	return (ct);
}

char	*ft_itoa(int n)
{
	char		*d;
	size_t		i;
	long int	p;
	size_t		count;

	i = 0;
	p = n;
	count = ft_count(p);
	d = (char *)malloc(count + 1);
	if (d == NULL)
		return (NULL);
	if (n == 0)
		d[i++] = '0';
	if (p < 0)
		d[i++] = '-';
	if (p < 0)
		p *= -1;
	while (p > 0)
	{
		d[i++] = p % 10 + '0';
		p = p / 10;
	}
	d[i] = '\0';
	return (ft_rev(d));
}
