/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambelghi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 23:17:33 by ambelghi          #+#    #+#             */
/*   Updated: 2019/04/20 20:55:42 by ambelghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, void const *src, size_t len)
{
	unsigned char	*temp_dest;
	size_t			i;

	if ((temp_dest = (unsigned char *)ft_strnew(len)) != NULL)
	{
		i = 0;
		while (i < len)
		{
			temp_dest[i] = ((unsigned char *)src)[i];
			i++;
		}
		i = 0;
		while (i < len)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)temp_dest)[i];
			i++;
		}
		free(temp_dest);
	}
	return (dst);
}
