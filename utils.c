/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarreir <bcarreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:16:40 by bcarreir          #+#    #+#             */
/*   Updated: 2022/06/07 14:52:56 by bcarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static char	*ft_putnbr(long nbr, char *byte, int i)
{
	if (nbr < 0)
	{
		nbr = -nbr;
		ft_putchar('-');
	}
	if (nbr >= 2)
	{
		ft_putnbr(nbr / 2, byte, --i);
		byte[i] = "01"[nbr % 2];
	}
	else
		byte[--i] = "01"[nbr % 2];
	return (byte);
}

char	*ft_itoa_bin(int nbr)
{
	char *byte;
	int	i;

	byte = ft_calloc(9, sizeof(char));
	if (!byte)
		return (NULL);
	byte[8] = 0;
	byte = ft_putnbr(nbr, byte, 8);
	i = -1;
	while (++i < 8)
		if (!byte[i])
			byte[i] = '0';
	return (byte);
}
