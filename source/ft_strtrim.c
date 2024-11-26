/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 16:02:31 by jaferna2          #+#    #+#             */
/*   Updated: 2024/10/01 10:13:04 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	st;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	st = 0;
	end = ft_strlen(s1);
	while (ft_strchr(set, s1[st]))
		st++;
	if (st == end)
		return (ft_strdup(""));
	while (ft_strchr(set, s1[end -1]))
		end--;
	return (ft_substr(s1, st, end - st));
}
