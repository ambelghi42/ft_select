/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambelghi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 12:47:23 by ambelghi          #+#    #+#             */
/*   Updated: 2019/06/18 23:27:08 by ambelghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;

	if ((new = ft_strnew(len)) && s != NULL)
	{
		i = 0;
		while (s[start] != '\0' && i < len)
			new[i++] = s[start++];
		return (new);
	}
	return (NULL);
}
