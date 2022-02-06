/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uint_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaishi <otaishi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 20:13:55 by otaishi           #+#    #+#             */
/*   Updated: 2020/12/27 12:25:51 by otaishi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		u_digit_len(long long num)
{
	int			i;
	long long	j;

	j = num;
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

int		u_putnbr_ret(unsigned int n)
{
	unsigned int	n2;
	int				fd;

	n2 = n;
	fd = 1;
	if (n > 9)
	{
		putnbr_ret(n2 / 10);
		ft_putchar_fd('0' + n2 % 10, fd);
	}
	else
	{
		ft_putchar_fd('0' + n2, fd);
	}
	return (u_digit_len(n));
}

int		u_put_a_len(unsigned int num, int num_len, t_flag *info)
{
	int		n;

	n = 0;
	n += write_ret('0', info->a_len - num_len);
	n += u_putnbr_ret(num);
	return (n);
}

int		uint_0_flag(unsigned int num, int num_len, t_flag *info)
{
	int		n;

	n = 0;
	if (info->acc != -1)
	{
		n += write_ret(' ', info->a_width - info->a_len);
		n += u_put_a_len(num, num_len, info);
	}
	else
	{
		n += write_ret('0', info->a_width - info->a_len);
		n += u_putnbr_ret(num);
	}
	return (n);
}
