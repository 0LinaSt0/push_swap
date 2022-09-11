/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalena <msalena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 21:10:32 by msalena           #+#    #+#             */
/*   Updated: 2021/08/20 21:10:33 by msalena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hst, const char *ndl, size_t len)
{
	size_t	i;

	i = 0;
	if (ft_strlen((char *)ndl) == 0)
		return ((char *)hst);
	while (hst[i] != '\0' && i < len && len - i >= ft_strlen((char *)ndl))
	{
		if (hst[i] == *ndl && ft_strncmp(hst + i, ndl,
				ft_strlen((char *)ndl)) == 0)
			return ((char *)(hst + i));
		i++;
	}
	return (NULL);
}
