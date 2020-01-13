/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambelghi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 13:09:16 by ambelghi          #+#    #+#             */
/*   Updated: 2019/04/15 19:15:02 by ambelghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		div;
	char	nbr;

	div = 1000000000;
	while ((n / div) == 0 && n != 0)
		div /= 10;
	if (n < 0 && write(fd, "-", 1))
		div *= -1;
	if (n == 0)
		div = 1;
	while (div != 0)
	{
		nbr = (n / div) + 48;
		write(fd, &nbr, 1);
		n %= div;
		div /= 10;
	}
}
