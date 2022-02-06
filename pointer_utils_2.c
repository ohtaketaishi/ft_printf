/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaishi <otaishi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 12:46:21 by otaishi           #+#    #+#             */
/*   Updated: 2020/12/28 13:26:44 by otaishi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		p_0_num(t_flag *info)
{
	int		n;

	n = 0;
	info->a_width = info->field > 3 ? info->field : 3;
	n += write_ret(' ', info->a_width - 3);
	n += write_ret('0', 1);
	n += write_ret('x', 1);
	return (n);
}
