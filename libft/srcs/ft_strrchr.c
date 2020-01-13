/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambelghi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 20:39:09 by ambelghi          #+#    #+#             */
/*   Updated: 2019/04/16 21:19:43 by ambelghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char const *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (s[i] != (char)c && i > 0)
		i--;
	return (s[i] == (char)c ? (char*)&s[i] : NULL);
}
