/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvarela <rvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:15:24 by rvarela           #+#    #+#             */
/*   Updated: 2024/03/17 12:50:56 by rvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	count_words(char *str, char sep)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		while (str[i] && str[i] == sep)
			i++;
		if (str[i])
			words++;
		while (str[i] && str[i] != sep)
			i++;
	}
	return (words);
}

static char	*ft_strcpy(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	s1 = (char *)malloc(sizeof(char) * (n + 1));
	if (!s1)
		return (NULL);
	while (s2[i] && i < n)
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

char	**ft_split(char *str, char sep)
{
	int		i;
	int		j;
	int		k;
	char	**res;

	res = (char **)malloc(sizeof(char *) * (count_words(str, sep) + 2));
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	k = 1;
	res[0] = ft_strcpy(res[0], "a.out", 5);
	while (str[i])
	{
		while (str[i] && str[i] == sep)
			i++;
		j = i;
		while (str[i] && str[i] != sep)
			i++;
		if (i > j)
		{
			res[k] = ft_strcpy(res[k], &str[j], i - j);
			k++;
		}
	}
	res[k] = NULL;
	return (res);
}
