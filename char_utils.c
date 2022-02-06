/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaishi <otaishi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 01:26:30 by otaishi           #+#    #+#             */
/*   Updated: 2020/12/27 13:22:55 by otaishi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		char_print(va_list *ap, t_flag *info)
{
	char	c;
	int		n;

	n = 0;
	c = (char)va_arg(*ap, int);
	info->a_width = info->field > 0 ? info->field : 1;
	if (info->flag1)
	{
		n += write_ret(c, 1);
		n += write_ret(' ', info->a_width - 1);
	}
	else if (!info->flag1 && !info->flag2)
	{
		n += write_ret(' ', info->a_width - 1);
		n += write_ret(c, 1);
	}
	else if (info->flag2)
	{
		n += write_ret('0', info->a_width - 1);
		n += write_ret(c, 1);
	}
	return (n);
}
