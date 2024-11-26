/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 12:55:00 by jaferna2          #+#    #+#             */
/*   Updated: 2024/09/26 10:04:59 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static size_t	ncount(int n)
{
	size_t	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*ns;
	size_t	i;
	size_t	z;
	long	temp_n;

	z = ncount(n);
	temp_n = n;
	ns = (char *)malloc((z + 1) * sizeof(char));
	if (!ns)
		return (NULL);
	i = z;
	if (n < 0)
		temp_n *= -1;
	ns[z] = '\0';
	if (n == 0)
		ns[--i] = '0';
	while (temp_n > 0)
	{
		ns[--i] = (temp_n % 10) + 48;
		temp_n /= 10;
	}
	if (n < 0)
		ns[--i] = '-';
	return (ns);
}
