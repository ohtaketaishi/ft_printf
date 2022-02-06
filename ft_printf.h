/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaishi <otaishi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 17:51:54 by otaishi           #+#    #+#             */
/*   Updated: 2020/12/28 13:06:07 by otaishi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# include <stdint.h>

typedef struct	s_flag
{
	int flag1;
	int flag2;
	int field;
	int acc;
	int specifier;
	int a_len;
	int a_width;
	int s_acc;
}				t_flag;

int				arg_print(const char **tmp, const char **fmt,
		va_list *ap, t_flag *info);
void			per_process(const char **tmp, const char **fmt,
		int *n, va_list *ap);
void			put_str(const char	**tmp, const char **fmt, int *n);
int				ft_printf(const char *fmt, ...);
int				input_field(const char **fmt, va_list *ap, t_flag *info);
int				input_acc(const char **fmt, va_list *ap, t_flag *info);
void			init_flag(t_flag *info);
int				ft_isdigit(int c);
void			*ft_memchr(const void *s, int c, size_t n);
size_t			ft_strlen(const char *s);
void			ft_putchar_fd(char c, int fd);
int				write_ret(char c, int n);
int				strchr_n(const char *s, int c);
int				non_specifier(const char **tmp, const char **fmt);
int				print_percent(t_flag *info);
int				put_a_width(int num, t_flag *info);
int				put_a_len(int num, int num_len, t_flag *info);
int				int_0_flag(int num, int num_len, t_flag *info);
int				int_0_num(t_flag *info);
int				int_print(va_list *ap, t_flag *info);
int				digit_len(int num);
int				putnbr_ret(long long n);
int				uint_u(unsigned int num, int num_len, t_flag *info);
int				uint_x(unsigned int num, int num_len, t_flag *info, int mode);
int				uint_print(va_list *ap, t_flag *info);
int				u_digit_len(long long num);
int				u_putnbr_ret(unsigned int n);
int				u_put_a_len(unsigned int num, int num_len, t_flag *info);
int				uint_0_flag(unsigned int num, int num_len, t_flag *info);
int				uint_hex_len(unsigned int n);
int				puthex_ret(unsigned int num, int mode);
int				x_put_a_len(unsigned int num, int num_len,
		t_flag *info, int mode);
int				x_0_flag(unsigned int num, int num_len, t_flag *info, int mode);
int				char_print(va_list *ap, t_flag *info);
int				put_string(char *s, int n);
int				string_print(va_list *ap, t_flag *info, int *n);
int				p_hex_len(uintptr_t n);
int				p_puthex_ret(uintptr_t num);
int				p_put_a_len(uintptr_t num, int num_len, t_flag *info);
int				p_0_flag(uintptr_t num, int num_len, t_flag *info);
int				pointer_print(va_list *ap, t_flag *info);
int				p_0_num(t_flag *info);

#endif
