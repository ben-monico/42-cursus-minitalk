/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarreir <bcarreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 23:21:45 by bcarreir          #+#    #+#             */
/*   Updated: 2022/06/07 18:07:35 by bcarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int ac, char **av)
{
	char	*byte;
	pid_t	srv_pid;
	int		i;
	int		j;

	if (ac != 3)
		return (1);
	srv_pid = ft_atoi(av[1]);
	if (!srv_pid)
		return (1);
	i = -1;
	while (av[2][++i])
	{
		byte = ft_itoa_bin(av[2][i]);
		if (!byte)
			return (1);
		j = -1;
		while (byte[++j])
		{
			if (byte[j] == '1')
			{
				kill(srv_pid, SIGUSR1);
				write(1, "1", 1);
			}
			else if (byte[j] == '0')
			{
				kill(srv_pid, SIGUSR2);
				write(1, "0", 1);
			}
			usleep(50);
		}
			write(1, "C", 1);
		free(byte);
		//send SIGNUSR depending on bit
	}
	return (0);
}
