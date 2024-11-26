/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 09:43:01 by jaferna2          #+#    #+#             */
/*   Updated: 2024/09/30 15:27:53 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static	size_t	word_count(char const *s, char c)
{
	size_t	i;
	size_t	wordnum;

	i = 0;
	wordnum = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			wordnum++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (wordnum);
}

static	void	free_ar(char **ar)
{
	size_t	i;

	i = 0;
	while (ar[i])
	{
		free(ar[i]);
		i++;
	}
	free(ar);
}

static	int	fill_ar(char **ar, char const *s, char c, size_t wordnum)
{
	size_t	i;
	size_t	word_init;
	size_t	word_indx;

	i = 0;
	word_indx = 0;
	while (s[i] && word_indx < wordnum)
	{
		while (s[i] == c)
			i++;
		word_init = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > word_init)
		{
			ar[word_indx] = ft_substr(s, word_init, i - word_init);
			if (!ar[word_indx])
			{
				free_ar(ar);
				return (0);
			}
			word_indx++;
		}
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	size_t	words;
	char	**ar;

	if (!s)
		return (NULL);
	words = word_count(s, c);
	ar = malloc((words + 1) * sizeof(char *));
	if (!ar)
		return (free_ar(ar), NULL);
	if (!fill_ar(ar, s, c, words))
		return (free_ar(ar), NULL);
	ar[words] = NULL;
	return (ar);
}
