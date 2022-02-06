/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaishi <otaishi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 00:21:08 by otaishi           #+#    #+#             */
/*   Updated: 2020/12/28 13:05:21 by otaishi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		p_hex_len(uintptr_t n)
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

int		p_puthex_ret(uintptr_t num)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (num / 16 != 0)
		p_puthex_ret(num / 16);
	write(1, &hex[num % 16], 1);
	return (p_hex_len(num));
}

int		p_put_a_len(uintptr_t num, int num_len, t_flag *info)
{
	int		n;

	n = 0;
	n += write_ret('0', info->a_len - num_len);
	n += p_puthex_ret(num);
	return (n);
}

int		p_0_flag(uintptr_t num, int num_len, t_flag *info)
{
	int		n;

	n = 0;
	if (info->acc != -1)
	{
		n += write_ret(' ', info->a_width - info->a_len - 2);
		n += (write_ret('0', 1) + write_ret('x', 1));
		n += p_put_a_len(num, num_len, info);
	}
	else
	{
		n += (write_ret('0', 1) + write_ret('x', 1));
		n += write_ret('0', info->a_width - info->a_len - 2);
		n += p_puthex_ret(num);
	}
	return (n);
}

int		pointer_print(va_list *ap, t_flag *info)
{
	uintptr_t		i;
	int				p_len;
	int				n;

	n = 0;
	if (!(i = (uintptr_t)va_arg(*ap, void *)) && (!info->s_acc || !info->acc))
		return (p_0_num(info));
	p_len = p_hex_len(i);
	info->a_len = p_len > info->acc ? p_len : info->acc;
	info->a_width = info->a_len > info->field ? info->a_len : info->field;
	if (info->flag1)
	{
		n += write_ret('0', 1) + write_ret('x', 1);
		n += p_put_a_len(i, p_len, info);
		n += write_ret(' ', info->a_width - info->a_len - 2);
	}
	else if (!info->flag1 && !info->flag2)
	{
		n += write_ret(' ', info->a_width - info->a_len - 2);
		n += write_ret('0', 1) + write_ret('x', 1);
		n += p_put_a_len(i, p_len, info);
	}
	else if (info->flag2)
		n += p_0_flag(i, p_len, info);
	return (n);
}
