/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambelghi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 00:05:19 by ambelghi          #+#    #+#             */
/*   Updated: 2019/04/20 21:26:53 by ambelghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int		i;
	char				*str;

	if (s != NULL && (*f) != NULL)
	{
		if ((str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))) != NULL)
		{
			i = 0;
			while (s[i] != '\0')
			{
				str[i] = (*f)(i, s[i]);
				i++;
			}
			str[i] = '\0';
			return (str);
		}
	}
	return (NULL);
}
