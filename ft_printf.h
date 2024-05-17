/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djelacik <djelacik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:38:02 by djelacik          #+#    #+#             */
/*   Updated: 2024/05/15 16:31:21 by djelacik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct s_util
{
	int	flag;
	int	total;
	int	width;
	int	arg_len;
	int	left_align;
	int	zero_fill;
	int	precision;
	int	space;
	int	hash;
	int	plus;
}	t_util;

int			ft_isdigit(int c);
void		ft_putchar(char c, t_util *str_util);
void		ft_putstr(char *s, t_util *str_util);
void		ft_hexa_base(unsigned long long nbr, char *base, t_util *info);
void		ft_putnbr(int nb, t_util *info);
void		ft_put_uns_nbr(unsigned int nb, t_util *info);
size_t		ft_strlen(const char *s);

void		print_char(va_list args, t_util *info);
void		print_str(va_list args, t_util *info);
void		print_ptr(va_list args, t_util *info);
void		print_hex_lower(va_list args, t_util *info);
void		print_hex_upper(va_list args, t_util *info);
void		print_int(va_list args, t_util *info);
void		print_uns_int(va_list args, t_util *info);

void		print_format(const char *str, va_list args, t_util *str_util);

int			ft_printf(const char *format, ...);
/*
**			Functions for bonus part
*/
void		*ft_memset(void *b, int c, size_t len);
void		*ft_bzero(void *s, size_t n);
void		arg_len_str(va_list args, t_util *info);
void		arg_len_int(va_list args, t_util *info);
void		arg_len_hex(va_list args, t_util *info);
void		parse_format(const char **format, t_util *info);
void		print_flags(const char *str, va_list args, t_util *info);
void		process_arg_len(const char *format, va_list args, t_util *info);
void		get_percision(const char **format, t_util *info);
void		parse_width(const char **format, t_util *info);
void		parse_flags(const char **format, t_util *info);

#endif