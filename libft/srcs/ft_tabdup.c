/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambelghi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 13:34:27 by ambelghi          #+#    #+#             */
/*   Updated: 2020/01/13 18:25:02 by ambelghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	**ft_tabdup(char **tab)
{
	char	**dup;
	int		i;

	dup = NULL;
	if (tab)
	{
		i = 0;
		while (tab[i])
			i++;
		if (!(dup = (char **)malloc(sizeof(char*) * (i + 1))))
			return (NULL);
		dup[i] = NULL;
		while (i-- > 0)
			dup[i] = ft_strdup(tab[i]);
	}
	return (dup);
}
