/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btb_conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarreir <bcarreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 16:40:01 by bcarreir          #+#    #+#             */
/*   Updated: 2022/06/15 16:53:21 by bcarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static char	*ft_putnbr_dec(long nbr, char *byte, int i)
{
	if (nbr < 0)
	{
		nbr = -nbr;
		ft_putchar('-');
	}
	if (nbr >= 10)
	{
		ft_putnbr_dec(nbr / 10, byte, --i);
		byte[i] = "0123456789"[nbr % 10];
	}
	else
		byte[--i] = "0123456789"[nbr % 10];
	return (byte);
}

char	*btoa(char *str)
{
	char	*byte;

	byte = ft_calloc(4, sizeof(char));
	if (!byte)
		return (NULL);
	byte[3] = 0;
	byte = ft_putnbr_dec(ft_atoi(str), byte, 3);
	printf("btoa %s\n", byte);
	return (byte);
}

char	*clean_output(int size, char *output)
{
	char	*clean_output;
	int		i;

	i = 0;
	clean_output = malloc(size);
	while (i <= size)
	{
		clean_output[i] = output[1023 - size + i];
		i++;
	}
	return (clean_output);
}

char	*convert_write(char *base, long nbr_l, int base_size)
{
	int		index;
	char	output[1024];
	int		size;
	int		neg;

	neg = 0;
	size = 0;
	index = 1023;
	if (nbr_l < 0)
	{
		neg = 1;
		nbr_l = -nbr_l;
	}
	while (nbr_l != 0)
	{
		output[index] = base[nbr_l % base_size];
		index--;
		nbr_l = nbr_l / base_size;
	}
	if (neg == 1)
		output[index] = '-';
	else
		index++;
	size = 1023 - index;
	return (clean_output(size, output));
}

char	*ft_putnbr_l_base(long nbr, char *base)
{
	int		base_size;

	base_size = 0;
	while (base[base_size] != '\0')
		base_size++;
	return (convert_write(base, nbr, base_size));
}
