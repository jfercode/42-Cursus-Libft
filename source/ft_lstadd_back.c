/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 11:32:34 by jaferna2          #+#    #+#             */
/*   Updated: 2024/09/27 11:59:54 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lback;

	if (!lst || !new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		lback = ft_lstlast(*lst);
		lback->next = new;
	}
}
