/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambelghi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 17:36:38 by ambelghi          #+#    #+#             */
/*   Updated: 2019/04/17 20:38:01 by ambelghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nbrlen(int n)
{
	unsigned int	nbr;
	int				len;

	if (n < 0)
	{
		len = 1;
		nbr = -n;
	}
	else
	{
		len = 0;
		nbr = n;
	}
	while (nbr / 10 != 0)
	{
		len++;
		nbr /= 10;
	}
	return (len);
}
