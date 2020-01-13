/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambelghi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 17:30:59 by ambelghi          #+#    #+#             */
/*   Updated: 2019/04/17 20:36:25 by ambelghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	unsigned int	nbr;
	int				len;
	char			*itoa;

	if (n < 0)
		nbr = -n;
	else
		nbr = n;
	len = ft_nbrlen(n);
	if ((itoa = ft_strnew(len + 1)) != NULL)
	{
		itoa[0] = 48;
		while (nbr != 0)
		{
			itoa[len--] = (nbr % 10) + 48;
			nbr /= 10;
		}
		if (n < 0)
			itoa[len] = '-';
		return (itoa);
	}
	return (NULL);
}
