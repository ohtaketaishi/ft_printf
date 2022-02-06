/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uint_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaishi <otaishi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 21:06:41 by otaishi           #+#    #+#             */
/*   Updated: 2020/12/27 15:47:24 by otaishi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		uint_hex_len(unsigned int n)
{
	int		ret;

	ret = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 16;
		ret++;
	}
	return (ret);
}

int		puthex_ret(unsigned int num, int mode)
{
	char	*hex;
	char	*hex_up;

	hex = "0123456789abcdef";
	hex_up = "0123456789ABCDEF";
	if (num / 16 != 0)
		puthex_ret(num / 16, mode);
	if (mode)
		write(1, &hex[num % 16], 1);
	else
		write(1, &hex_up[num % 16], 1);
	return (uint_hex_len(num));
}

int		x_put_a_len(unsigned int num, int num_len, t_flag *info, int mode)
{
	int		n;

	n = 0;
	n += write_ret('0', info->a_len - num_len);
	n += puthex_ret(num, mode);
	return (n);
}

int		x_0_flag(unsigned int num, int num_len, t_flag *info, int mode)
{
	int		n;

	n = 0;
	if (info->acc != -1)
	{
		n += write_ret(' ', info->a_width - info->a_len);
		n += x_put_a_len(num, num_len, info, mode);
	}
	else
	{
		n += write_ret('0', info->a_width - info->a_len);
		n += puthex_ret(num, mode);
	}
	return (n);
}
