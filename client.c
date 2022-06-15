/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarreir <bcarreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 23:21:45 by bcarreir          #+#    #+#             */
/*   Updated: 2022/06/15 17:11:17 by bcarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static char	*ft_putnbr_bin(long nbr, char *byte, int i)
{
	if (nbr < 0)
	{
		nbr = -nbr;
		ft_putchar('-');
	}
	if (nbr >= 2)
	{
		ft_putnbr_bin(nbr / 2, byte, --i);
		byte[i] = "01"[nbr % 2];
	}
	else
		byte[--i] = "01"[nbr % 2];
	return (byte);
}

char	*ft_ctob(int nbr)
{
	char	*byte;
	int		i;

	byte = ft_calloc(9, sizeof(char));
	if (!byte)
		return (NULL);
	ft_memset(byte, '0', 8);
	byte = ft_putnbr_bin(nbr, byte, 8);
	i = -1;
	while (++i < 8)
		if (!byte[i])
			byte[i] = '0';
	return (byte);
}

void	convert_and_kill(char *str, pid_t pid)
{
	char	*byte;
	int		i;
	int		j;

	i = -1;
	while (str[++i])
	{
		byte = ft_ctob(str[i]);
		if (!byte)
			return ;
		if (!str[i + 1])
			byte[0] = '1';
		j = -1;
		while (byte[++j])
		{
			if (byte[j] == '1')
				kill(pid, SIGUSR1);
			else if (byte[j] == '0')
				kill(pid, SIGUSR2);
			usleep(500);
		}
		free(byte);
	}
	return ;
}

int	main(int ac, char **av)
{
	pid_t	srv_pid;

	if (ac != 3)
		return (1);
	srv_pid = ft_atoi(av[1]);
	if (!srv_pid)
		return (1);
	convert_and_kill(av[2], srv_pid);
	return (0);
}
