/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambelghi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 12:01:10 by ambelghi          #+#    #+#             */
/*   Updated: 2019/12/02 13:48:07 by ambelghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countwords(char const *s, char *c)
{
	int				words;
	unsigned int	i;

	i = 0;
	words = 0;
	while (s[i] != '\0')
	{
		if (!ft_strchr(c, s[i]) && ((i > 0) ? (int)ft_strchr(c, s[i - 1]) : 1))
			words++;
		i++;
	}
	return (words);
}
