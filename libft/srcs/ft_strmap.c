/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambelghi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 23:48:40 by ambelghi          #+#    #+#             */
/*   Updated: 2019/04/16 21:50:56 by ambelghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*str;

	if (s != NULL && (*f) != NULL)
	{
		i = ft_strlen(s);
		if ((str = (char *)malloc(sizeof(char) * (i + 1))) != NULL)
		{
			str[i] = '\0';
			while (i-- > 0)
				str[i] = (*f)(s[i]);
			return (str);
		}
	}
	return (NULL);
}
