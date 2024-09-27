/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 10:08:21 by jaferna2          #+#    #+#             */
/*   Updated: 2024/09/26 14:23:19 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

t_list	*ft_lstnew_bonus(void *content)
{
	t_list	*nlst;	

	nlst = malloc(sizeof(t_list));
	if (!nlst)
		return (NULL);
	nlst->content = content;
	nlst->next = (NULL);
	return (nlst);
}
