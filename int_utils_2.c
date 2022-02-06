/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaishi <otaishi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 01:08:17 by otaishi           #+#    #+#             */
/*   Updated: 2020/12/27 12:22:43 by otaishi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		digit_len(int num)
{
	int			i;
	long long	j;

	j = (long long)num;
	i = 0;
	if (j < 0)
		j *= -1;
	if (!(j % 10))
		j = j + 1;
	while (j)
	{
		j = j / 10;
		i++;
	}
	return (i);
}

int		putnbr_ret(long long n)
{
	unsigned int	un_nbr;
	int				fd;

	fd = 1;
	un_nbr = (unsigned int)n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		un_nbr = (unsigned int)(-1 * n);
	}
	if (un_nbr > 9)
	{
		putnbr_ret(un_nbr / 10);
		ft_putchar_fd('0' + un_nbr % 10, fd);
	}
	else
	{
		ft_putchar_fd('0' + un_nbr, fd);
	}
	return (digit_len(n));
}
