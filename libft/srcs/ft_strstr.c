/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambelghi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 20:42:04 by ambelghi          #+#    #+#             */
/*   Updated: 2019/04/20 21:03:18 by ambelghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char const *haystack, char const *needle)
{
	char	*oc;

	oc = ft_strchr(haystack, (int)needle[0]);
	while (oc != NULL && needle[0] != '\0')
	{
		if (ft_strnequ(oc, needle, ft_strlen(needle)) == 1)
			return (oc);
		oc = ft_strchr(++oc, (int)needle[0]);
	}
	return (needle[0] == '\0' ? (char *)haystack : NULL);
}
