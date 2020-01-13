/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambelghi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 22:36:26 by ambelghi          #+#    #+#             */
/*   Updated: 2020/01/08 16:25:53 by ambelghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_strsplitter(char *c, char const *s, char **str_split, int words)
{
	int	len;
	int	temp_words;
	int	i;

	i = 0;
	temp_words = 0;
	while (temp_words < words)
	{
		len = 0;
		while (ft_strchr(c, s[i]))
			i++;
		while (s[i] != '\0' && !ft_strchr(c, s[i]))
		{
			len++;
			i++;
		}
		str_split[temp_words] = ft_strsub(s, (i - len), len);
		temp_words++;
	}
	str_split[temp_words] = 0;
}

char		**ft_strsplit(char const *s, char *c)
{
	char	**str_split;
	int		words;

	if (s != NULL && c)
	{
		words = ft_countwords(s, c);
		if (words > 0
			&& (str_split = (char **)malloc(sizeof(char *) * (words + 1)))
			!= NULL)
		{
			ft_strsplitter(c, s, str_split, words);
			return (str_split);
		}
	}
	return (NULL);
}
