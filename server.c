/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarreir <bcarreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 22:29:39 by bcarreir          #+#    #+#             */
/*   Updated: 2022/06/07 17:51:41 by bcarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char 	*addbit(char c)
{
	static char	*binstr;
	char	*tmp;
	int		len;

	len = 0;
	tmp = binstr;
	if (tmp)
		len = ft_strlen(tmp);
	binstr = malloc(sizeof(char) * (len + 2));
	if (!binstr)
		return (NULL);
	ft_memcpy(binstr, tmp, len);
	free(tmp);
	tmp = &c;
	binstr[len] = *tmp;
	binstr[len + 1] = 0;
	printf("str is %s\n", binstr);
	return (binstr);
}

void	sighandler(int signum)
{
	

	if (signum == SIGUSR1)
	{
		// write(1, "1", 1);
		addbit('1');
	}
	else if (signum == SIGUSR2)
	{
		// write(1, "0", 1);
		addbit('0');
	}
	if (!signum)
	return ;
	return ;
}

int	main(void)
{
	int	pid;
	// int	i;

	pid = getpid();
	ft_printf("%d\n", pid);
	signal(SIGUSR1, sighandler);
	signal(SIGUSR2, sighandler);
	// i = 0;
	// while (1)
	// {
		while (1)
		{
		pause();
		}
	// }
}
// receive signusr. register char every 8 bits. if 8 bits are 0s, then end reception, print str and exit