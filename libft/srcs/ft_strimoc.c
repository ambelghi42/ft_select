/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strimoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambelghi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 21:03:40 by ambelghi          #+#    #+#             */
/*   Updated: 2019/07/13 21:07:30 by ambelghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strimoc(char const *s, char oc)
{
	unsigned int	end;
	unsigned int	start;
	char			*new;

	if (s != NULL)
	{
		if (*s != '\0')
		{
			start = 0;
			while (s[start] == oc)
				start++;
			end = (unsigned int)(ft_strlen((char *)s) - 1);
			while (s[end] == oc && end > start)
				end--;
			new = ft_strsub((char *)s, (int)start, (size_t)((end - start) + 1));
			return (new);
		}
		return ("\0");
	}
	return (NULL);
}
