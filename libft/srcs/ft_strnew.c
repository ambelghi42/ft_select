/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambelghi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 21:58:11 by ambelghi          #+#    #+#             */
/*   Updated: 2019/04/20 21:19:21 by ambelghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*mem;
	size_t	i;

	i = 0;
	if ((mem = (char*)malloc(sizeof(char) * (size + 1))) != NULL)
	{
		while (i <= size)
			mem[i++] = '\0';
		return (mem);
	}
	return (NULL);
}
