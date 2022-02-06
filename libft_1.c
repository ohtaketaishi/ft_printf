/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaishi <otaishi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 00:59:24 by otaishi           #+#    #+#             */
/*   Updated: 2020/12/27 12:17:41 by otaishi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*copybuf;

	copybuf = (unsigned char *)s;
	while (n-- > 0)
	{
		if (*copybuf++ == (unsigned char)c)
		{
			return (--copybuf);
		}
	}
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
