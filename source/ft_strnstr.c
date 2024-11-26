/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:37:34 by jaferna2          #+#    #+#             */
/*   Updated: 2024/09/25 14:47:42 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*b;
	char	*l;
	size_t	i;
	size_t	j;

	b = (char *)big;
	l = (char *)little;
	i = 0;
	j = 0;
	if (*l == '\0')
		return (b);
	while (i < len && b[i])
	{
		j = 0;
		while (i + j < len && b[i + j] && l[j] && b[i + j] == l[j])
			j++;
		if (l[j] == '\0')
			return (&b[i]);
		i++;
	}
	return (NULL);
}
