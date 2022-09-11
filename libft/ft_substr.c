/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalena <msalena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 21:10:42 by msalena           #+#    #+#             */
/*   Updated: 2021/08/20 21:10:42 by msalena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*d;
	char	*t;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	if (start >= ft_strlen((char *)s))
	{
		t = malloc(1);
		*t = '\0';
		return (t);
	}
	if (len > ft_strlen((char *)s) - start)
		len = ft_strlen((char *)s) - start;
	d = (char *)malloc(len + 1);
	if (d == NULL)
		return (NULL);
	while (s[start] != '\0' && i < len)
		d[i++] = s[start++];
	d[i] = '\0';
	return (d);
}
