/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarreir <bcarreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 22:32:00 by bcarreir          #+#    #+#             */
/*   Updated: 2022/06/15 16:59:11 by bcarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "libft.h"
# include "libftprintf.h"
# include <unistd.h>
# include <signal.h>
# include <stdio.h>
# include <math.h>

char	*ft_convert_base(char *nbr, char *base_from, char *base_to);
char	*ft_putnbr_l_base(long nbr, char *base);

#endif