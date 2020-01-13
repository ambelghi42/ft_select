/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambelghi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 20:18:57 by ambelghi          #+#    #+#             */
/*   Updated: 2019/11/27 14:26:16 by ambelghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(char const *str)
{
	int				neg;
	unsigned int	n;
	int				i;

	i = 0;
	neg = 1;
	n = 0;
	if (str)
	{
		while (str[i] == '\t' || str[i] == '\n' || str[i] == '\r'
				|| str[i] == '\v' || str[i] == '\f' || str[i] == ' ')
			i++;
		if (str[i] == '-')
			neg = -1;
		if (str[i] == '+' || str[i] == '-')
			i++;
		while (('0' <= str[i] && str[i] <= '9') && str[i] != '\0')
			n = n * 10 + str[i++] - '0';
	}
	return (n * neg);
}
