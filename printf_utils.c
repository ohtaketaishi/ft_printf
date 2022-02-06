/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaishi <otaishi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 12:04:03 by otaishi           #+#    #+#             */
/*   Updated: 2020/12/27 23:44:23 by otaishi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		input_field(const char **fmt, va_list *ap, t_flag *info)
{
	int		ret;

	ret = 0;
	if (**fmt == '*')
	{
		ret = va_arg(*ap, int);
		(*fmt)++;
		if (ret < 0)
		{
			ret *= -1;
			info->flag1 = 1;
		}
		return (ret);
	}
	else if (ft_isdigit(**fmt))
	{
		while (ft_isdigit(**fmt))
		{
			ret = (ret * 10) + (**fmt - '0');
			(*fmt)++;
		}
		return (ret);
	}
	return (-1);
}

int		input_acc(const char **fmt, va_list *ap, t_flag *info)
{
	int		ret;

	ret = 0;
	if (**fmt == '*')
	{
		ret = va_arg(*ap, int);
		(*fmt)++;
		if (ret < 0)
			return (-1);
		return (ret);
	}
	else if (ft_isdigit(**fmt))
	{
		while (ft_isdigit(**fmt))
		{
			ret = (ret * 10) + (**fmt - '0');
			(*fmt)++;
		}
		return (ret);
	}
	info->s_acc = 0;
	return (-1);
}

void	init_flag(t_flag *info)
{
	info->flag1 = 0;
	info->flag2 = 0;
	info->field = -1;
	info->acc = -1;
	info->specifier = -1;
	info->a_len = 0;
	info->a_width = 0;
	info->s_acc = -1;
}
