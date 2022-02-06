/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaishi <otaishi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 17:46:39 by otaishi           #+#    #+#             */
/*   Updated: 2020/12/27 23:44:05 by otaishi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		arg_print(const char **tmp, const char **fmt, va_list *ap, t_flag *info)
{
	int		num;

	num = 0;
	if (info->specifier == -1)
		return (non_specifier(tmp, fmt));
	(*fmt)++;
	if (info->specifier == 0)
		num = char_print(ap, info);
	else if (info->specifier == 1)
		string_print(ap, info, &num);
	else if (info->specifier == 2)
		num = pointer_print(ap, info);
	else if (info->specifier == 3 || info->specifier == 4)
		num = int_print(ap, info);
	else if (info->specifier >= 5 && info->specifier <= 7)
		num = uint_print(ap, info);
	else
		num = print_percent(info);
	return (num);
}

void	per_process(const char **tmp, const char **fmt, int *n, va_list *ap)
{
	int		num;
	t_flag	info;

	(*fmt)++;
	init_flag(&info);
	while ((ft_memchr(*fmt, '-', 1)) || ft_memchr(*fmt, '0', 1))
	{
		if (**fmt == '-')
			info.flag1 = 1;
		else
			info.flag2 = 1;
		(*fmt)++;
	}
	info.field = input_field(fmt, ap, &info);
	if (**fmt == '.')
	{
		(*fmt)++;
		info.acc = input_acc(fmt, ap, &info);
	}
	info.specifier = strchr_n("cspdiuxX%", **fmt);
	num = arg_print(tmp, fmt, ap, &info);
	*n = num >= 0 ? num + *n : num;
}

void	put_str(const char **tmp, const char **fmt, int *n)
{
	while (**fmt != '%' && **fmt)
		(*fmt)++;
	write(1, *tmp, *fmt - *tmp);
	*n += *fmt - *tmp;
}

int		ft_printf(const char *fmt, ...)
{
	va_list		ap;
	int			n;
	const char	*tmp;

	n = 0;
	va_start(ap, fmt);
	if (fmt == NULL)
		return (-1);
	while (n >= 0 && *fmt)
	{
		tmp = fmt;
		if (*tmp != '%')
			put_str(&tmp, &fmt, &n);
		else
			per_process(&tmp, &fmt, &n, &ap);
	}
	va_end(ap);
	return (n);
}
