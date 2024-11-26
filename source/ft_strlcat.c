/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 10:25:31 by jaferna2          #+#    #+#             */
/*   Updated: 2024/09/18 14:36:41 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_l;
	size_t	src_l;
	size_t	i;

	dst_l = 0;
	src_l = 0;
	while (dst[dst_l] && dst_l < size)
		dst_l++;
	while (src[src_l])
		src_l++;
	if (size <= dst_l)
		return (size + src_l);
	i = 0;
	while (src[i] && (dst_l + i) < size - 1)
	{
		dst[dst_l + i] = src[i];
		i++;
	}
	if (dst_l + i < size)
		dst[dst_l + i] = '\0';
	return (dst_l + src_l);
}
