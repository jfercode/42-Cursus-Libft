/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:37:32 by jaferna2          #+#    #+#             */
/*   Updated: 2024/09/18 16:11:20 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*p01;
	unsigned char	*p02;

	i = 0;
	p01 = (unsigned char *) dest;
	p02 = (unsigned char *) src;
	while (i < n)
	{
		p01[i] = p02[i];
		i++;
	}
	return (dest);
}
