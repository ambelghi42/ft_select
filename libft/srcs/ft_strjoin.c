/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambelghi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 15:19:06 by ambelghi          #+#    #+#             */
/*   Updated: 2019/07/13 22:46:08 by ambelghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str_join;
	int		i;
	int		z;

	if (!(s1 && s2))
		return (ft_strdup(s1 ? s1 : s2));
	if ((str_join = ft_strnew(ft_strlen(s1) + ft_strlen(s2))) != NULL)
	{
		i = 0;
		z = 0;
		while (s1[z] != '\0')
			str_join[i++] = s1[z++];
		z = 0;
		while (s2[z] != '\0')
			str_join[i++] = s2[z++];
		return (str_join);
	}
	return (NULL);
}
