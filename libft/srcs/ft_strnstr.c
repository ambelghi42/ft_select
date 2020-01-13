/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambelghi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 00:48:09 by ambelghi          #+#    #+#             */
/*   Updated: 2019/04/20 20:46:02 by ambelghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char const *haystack, char const *needle, size_t len)
{
	char	*oc;
	int		len_needle;

	len_needle = ft_strlen(needle);
	if ((int)len > ft_strlen(haystack))
		len = ft_strlen(haystack);
	oc = ft_strsub(haystack, 0, len);
	oc = ft_strchr(oc, (int)needle[0]);
	while (oc != NULL && needle[0] != '\0')
	{
		if (ft_strnequ(oc, needle, len_needle) == 1)
			return ((char*)&haystack[len - ft_strlen(oc)]);
		oc = ft_strchr(++oc, (int)needle[0]);
	}
	return (needle[0] == '\0' ? (char *)&haystack[0] : NULL);
}
