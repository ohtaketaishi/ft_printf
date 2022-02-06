/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uint_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaishi <otaishi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 23:48:35 by otaishi           #+#    #+#             */
/*   Updated: 2020/12/27 12:24:30 by otaishi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		uint_u(unsigned int num, int num_len, t_flag *info)
{
	int		n;

	n = 0;
	if (!num && (!info->s_acc || !info->acc))
		return (int_0_num(info));
	info->a_len = num_len > info->acc ? num_len : info->acc;
	info->a_width = info->a_len > info->field ? info->a_len : info->field;
	if (info->flag1)
	{
		n += u_put_a_len(num, num_len, info);
		n += write_ret(' ', info->a_width - info->a_len);
	}
	else if (!info->flag1 && !info->flag2)
	{
		n += write_ret(' ', info->a_width - info->a_len);
		n += u_put_a_len(num, num_len, info);
	}
	else if (info->flag2)
		n += uint_0_flag(num, num_len, info);
	return (n);
}

int		uint_x(unsigned int num, int num_len, t_flag *info, int mode)
{
	int		n;

	n = 0;
	if (!num && (!info->s_acc || !info->acc))
		return (int_0_num(info));
	info->a_len = num_len > info->acc ? num_len : info->acc;
	info->a_width = info->a_len > info->field ? info->a_len : info->field;
	if (info->flag1)
	{
		n += x_put_a_len(num, num_len, info, mode);
		n += write_ret(' ', info->a_width - info->a_len);
	}
	else if (!info->flag1 && !info->flag2)
	{
		n += write_ret(' ', info->a_width - info->a_len);
		n += x_put_a_len(num, num_len, info, mode);
	}
	else if (info->flag2)
		n += x_0_flag(num, num_len, info, mode);
	return (n);
}

int		uint_print(va_list *ap, t_flag *info)
{
	unsigned int	num;
	int				num_len;
	int				hex_len;
	int				n;

	n = 0;
	num = (unsigned int)va_arg(*ap, int);
	num_len = u_digit_len(num);
	hex_len = uint_hex_len(num);
	if (info->specifier == 5)
		n += uint_u(num, num_len, info);
	else if (info->specifier == 6)
		n += uint_x(num, hex_len, info, 1);
	else if (info->specifier == 7)
		n += uint_x(num, hex_len, info, 0);
	return (n);
}
