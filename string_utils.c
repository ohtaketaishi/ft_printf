/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaishi <otaishi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 15:34:41 by otaishi           #+#    #+#             */
/*   Updated: 2020/12/27 16:02:08 by otaishi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		put_string(char *s, int n)
{
	write(1, s, n);
	return (n);
}

int		string_print(va_list *ap, t_flag *info, int *n)
{
	char	*s;

	if (!(s = (char *)va_arg(*ap, char *)))
		s = "(null)";
	info->acc = info->acc == -1 ? INT_MAX : info->acc;
	info->acc = info->s_acc == 0 ? 0 : info->acc;
	info->a_len = (int)ft_strlen(s) > info->acc ? info->acc : ft_strlen(s);
	info->a_width = info->field > info->a_len ? info->field : info->a_len;
	if (info->flag1)
	{
		*n += put_string(s, info->a_len);
		*n += write_ret(' ', info->a_width - info->a_len);
	}
	else if (!info->flag1 && !info->flag2)
	{
		*n += write_ret(' ', info->a_width - info->a_len);
		*n += put_string(s, info->a_len);
	}
	else if (info->flag2)
	{
		*n += write_ret('0', info->a_width - info->a_len);
		*n += put_string(s, info->a_len);
	}
	return (*n);
}
