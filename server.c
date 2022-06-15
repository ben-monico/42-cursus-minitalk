/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarreir <bcarreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 22:29:39 by bcarreir          #+#    #+#             */
/*   Updated: 2022/06/15 17:10:57 by bcarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	clearbin_joinbit(char **binstr, int end)
{
	static char	*str;
	char		*tmp;
	int			tmp2;

	if (end)
		*binstr[0] = '0';
	tmp = str;
	tmp2 = ft_atoi(ft_convert_base(*binstr, "01", "0123456789"));
	str = ft_strjoin(tmp, (char *)&tmp2);
	if (tmp)
		free(tmp);
	free(*binstr);
	*binstr = NULL;
	if (end)
	{
		ft_printf("%s\n", str);
		free(str);
		str = NULL;
	}
	return ;
}

void	addbit(char c)
{
	static char	*binstr;
	char		*tmp;
	int			len;

	tmp = binstr;
	len = ft_strlen(tmp);
	binstr = ft_calloc(ft_strlen(tmp) + 2, sizeof(char));
	if (!binstr)
		return ;
	ft_memcpy(binstr, tmp, len);
	if (tmp)
		free(tmp);
	binstr[len] = c;
	if (ft_strlen(binstr) == 8)
		clearbin_joinbit(&binstr, binstr[0] - 48);
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
		pause();
}
