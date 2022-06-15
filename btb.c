/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarreir <bcarreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 18:39:01 by bcarreir          #+#    #+#             */
/*   Updated: 2022/06/15 17:02:23 by bcarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_r_pow(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	if (power > 0)
	{
		nb = nb * ft_r_pow(nb, power - 1);
		return (nb);
	}
	else
		return (nb);
}

long	get_index_base(char *base, char value)
{
	long	result;
	int		i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == value)
			result = i;
		i++;
	}
	return (result);
}

long	convert_to_decimal(char *nbr, char *base_from)
{
	int		base_size;
	int		i;
	long	result;
	int		nbr_size;

	base_size = 0;
	nbr_size = 0;
	while (base_from[base_size] != '\0')
		base_size++;
	while (nbr[nbr_size] != '\0')
		nbr_size++;
	i = 1;
	result = 0;
	while (i <= nbr_size)
	{
		result = result + (get_index_base(base_from, nbr[i - 1]))
			* (ft_r_pow(base_size, nbr_size - i));
		i++;
	}
	return (result);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*str;
	long	a;
	int		neg;

	if (nbr[0] == '-')
	{
		neg = 1;
		nbr++;
	}
	else
		neg = 0;
	a = convert_to_decimal(nbr, base_from);
	if (neg % 2 != 0)
		a = -a;
	str = ft_putnbr_l_base(a, base_to);
	return (str);
}
