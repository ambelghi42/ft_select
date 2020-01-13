/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambelghi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 02:58:56 by ambelghi          #+#    #+#             */
/*   Updated: 2019/04/24 13:36:42 by ambelghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *s1, char const *s2, size_t size)
{
	size_t	res;

	res = ft_strlen(s2) + size;
	if ((int)size > ft_strlen(s1))
	{
		res = (size_t)(ft_strlen(s1) + ft_strlen(s2));
		ft_strncat(s1, s2, size - ft_strlen(s1) - 1);
	}
	return (res);
}
