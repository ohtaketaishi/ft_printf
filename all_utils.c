/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaishi <otaishi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 23:41:05 by otaishi           #+#    #+#             */
/*   Updated: 2020/12/27 12:18:58 by otaishi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		write_ret(char c, int n)
{
	int		i;

	i = n;
	while (n > 0)
	{
		write(1, &c, 1);
		n--;
	}
	if (i >= 0)
		return (i);
	else
		return (0);
}

int		strchr_n(const char *s, int c)
{
	int		i;

	i = 0;
	if (c == '\0')
		return (-1);
	while (1)
	{
		if (*s == (char)c)
			return (i);
		if (*s == '\0')
			return (-1);
		i++;
		s++;
	}
}

int		non_specifier(const char **tmp, const char **fmt)
{
	if (**fmt)
		return (-1);
	write(1, *tmp, *fmt - *tmp);
	return (*fmt - *tmp);
}

int		print_percent(t_flag *info)
{
	info->field = (info->field > 1 ? info->field - 1 : 0);
	if (!info->flag1 && !info->flag2)
		write_ret(' ', info->field);
	if (!info->flag1 && info->flag2)
		write_ret('0', info->field);
	write(1, "%", 1);
	if (info->flag1)
		write_ret(' ', info->field);
	return (info->field + 1);
}
