/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalena <msalena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 21:10:10 by msalena           #+#    #+#             */
/*   Updated: 2021/08/20 21:10:10 by msalena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*d;
	size_t	i;

	if (!s1 || !s2)
		return (0);
	d = (char *)malloc(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1);
	if (d == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		d[i] = s1[i];
		i++;
	}
	while (*s2)
	{
		d[i] = *s2;
		i++;
		s2++;
	}
	d[i] = '\0';
	return (d);
}
