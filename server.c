/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarreir <bcarreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 22:29:39 by bcarreir          #+#    #+#             */
/*   Updated: 2022/06/08 18:41:26 by bcarreir         ###   ########.fr       */
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
	if (nbr >= 10)
	{
		ft_putnbr(nbr / 10, byte, --i);
		byte[i] = "0123456789"[nbr % 10];
	}
	else
		byte[--i] = "0123456789"[nbr % 10];
	return (byte);
}

char	*btoa(char *str)
{
	char *byte;

	byte = ft_calloc(4, sizeof(char));
	if (!byte)
		return (NULL);
	byte[3] = 0;
	byte = ft_putnbr(ft_atoi(str), byte, 3);
	printf("btoa %s\n", byte);
	return (byte);
}

void	addbit(char c)
{
	static char	*binstr;
	static char	*str;
	char		*tmp;
	int			tmp2;
	int			len;

	len = 0;
	tmp = binstr;
	if (tmp)
		len = ft_strlen(tmp);
	binstr = ft_calloc(len + 2, sizeof(char));
	if (!binstr)
		return ;
	ft_memcpy(binstr, tmp, len);
	if (tmp)
		free(tmp);
	binstr[len] = c;
	if (ft_strlen(binstr) == 8)
	{
		if (binstr[0] == '1')
		{
			tmp = str;
			binstr[0] = '0';
			tmp2 = ft_atoi(ft_convert_base(binstr, "01", "0123456789"));
			str = ft_strjoin(tmp, (char *)&tmp2);
			if (tmp)
				free(tmp);
			ft_printf("%s\n", str);
			free(str);
			free(binstr);
			binstr = NULL;
			str = NULL;
			return ;
		}
		tmp = str;
		tmp2 = ft_atoi(ft_convert_base(binstr, "01", "0123456789"));
		str = ft_strjoin(tmp, (char *)&tmp2);
		if (tmp)
			free(tmp);
		free(binstr);
		binstr = NULL;
	}	
	return ;
}

void	sighandler(int signum)
{
	if (signum == SIGUSR1)
		addbit('1');
	else if (signum == SIGUSR2)
		addbit('0');
	return ;
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("%d\n", pid);
	signal(SIGUSR1, sighandler);
	signal(SIGUSR2, sighandler);
while (1)
{
	pause();
}
}
// receive signusr. register char every 8 bits. if 8 bits are 0s, then end reception, print str and exit