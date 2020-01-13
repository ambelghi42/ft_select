/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcheck.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambelghi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 15:45:44 by ambelghi          #+#    #+#             */
/*   Updated: 2020/01/10 20:19:43 by ambelghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcheck(char const *s, char *oc)
{
	int i;

	if (s && oc)
	{
		i = 0;
		while (oc[i])
			if (ft_strchr(s, oc[i++]))
				return (0);
		return (1);
	}
	return (0);
}
