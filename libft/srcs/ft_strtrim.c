/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambelghi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 17:01:36 by ambelghi          #+#    #+#             */
/*   Updated: 2019/04/24 14:36:11 by ambelghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	unsigned int	end;
	unsigned int	start;
	char			*new;

	if (s != NULL)
	{
		if (*s != '\0')
		{
			start = 0;
			while ((s[start] == ' ' || s[start] == '\n' || s[start] == '\t'))
				start++;
			end = (unsigned int)(ft_strlen((char *)s) - 1);
			while ((s[end] == ' ' || s[end] == '\n' || s[end] == '\t')
						&& end > start)
				end--;
			new = ft_strsub((char *)s, (int)start, (size_t)((end - start) + 1));
			return (new);
		}
		return ("\0");
	}
	return (NULL);
}
