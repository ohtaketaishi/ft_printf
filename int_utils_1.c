/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_utils_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaishi <otaishi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 23:30:10 by otaishi           #+#    #+#             */
/*   Updated: 2020/12/27 15:39:34 by otaishi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		put_a_width(int num, t_flag *info)
{
	int		n;

	n = 0;
	if (num < 0)
	{
		n += write_ret('-', 1);
		n += write_ret('0', info->a_width - info->a_len);
		n += putnbr_ret(-(long long)num);
	}
	else
	{
		n += write_ret('0', info->a_width - info->a_len);
		n += putnbr_ret(num);
	}
	return (n);
}

int		put_a_len(int num, int num_len, t_flag *info)
{
	int		n;

	n = 0;
	if (num < 0)
	{
		n += write_ret('-', 1);
		n += write_ret('0', info->a_len - num_len - 1);
		n += putnbr_ret(-(long long)num);
	}
	else
	{
		n += write_ret('0', info->a_len - num_len);
		n += putnbr_ret(num);
	}
	return (n);
}

int		int_0_flag(int num, int num_len, t_flag *info)
{
	int		n;

	n = 0;
	if (info->acc != -1)
	{
		n += write_ret(' ', info->a_width - info->a_len);
		n += put_a_len(num, num_len, info);
	}
	else if (num < 0)
		n += put_a_width(num, info);
	else
	{
		n += write_ret('0', info->a_width - info->a_len);
		n += putnbr_ret(num);
	}
	return (n);
}

int		int_0_num(t_flag *info)
{
	int		n;

	n = 0;
	info->a_width = info->field > 0 ? info->field : 0;
	n += write_ret(' ', info->a_width);
	return (n);
}

int		int_print(va_list *ap, t_flag *info)
{
	int		num;
	int		num_len;
	int		n;

	n = 0;
	if (!(num = (int)va_arg(*ap, int)) && (!info->s_acc || !info->acc))
		return (int_0_num(info));
	num_len = digit_len(num);
	info->a_len = num_len > info->acc ? num_len : info->acc;
	if (num < 0)
		info->a_len += 1;
	info->a_width = info->a_len > info->field ? info->a_len : info->field;
	if (info->flag1)
	{
		n += put_a_len(num, num_len, info);
		n += write_ret(' ', info->a_width - info->a_len);
	}
	else if (!info->flag1 && !info->flag2)
	{
		n += write_ret(' ', info->a_width - info->a_len);
		n += put_a_len(num, num_len, info);
	}
	else if (info->flag2)
		n += int_0_flag(num, num_len, info);
	return (n);
}
