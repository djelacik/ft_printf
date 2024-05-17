/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djelacik <djelacik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:00:49 by djelacik          #+#    #+#             */
/*   Updated: 2024/05/15 13:56:22 by djelacik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_spaces(int count, t_util *info)
{
	while (count-- > 0)
		ft_putchar(' ', info);
}

static void	print_zeros(int count, t_util *info)
{
	while (count-- > 0)
		ft_putchar('0', info);
}

static void	print_precision(int count, t_util *info)
{
	while (count-- > 0)
		ft_putchar('0', info);
}

static void	print_prefix(t_util *info, const char *format)
{
	if (info->hash && (*format == 'x' || *format == 'X'))
	{
		ft_putchar('0', info);
		ft_putchar(*format, info);
	}
	else if (info->plus && (*format == 'd' || *format == 'i'))
	{
		ft_putchar('+', info);
	}
	else if (info->space && (*format == 'd' || *format == 'i'))
	{
		ft_putchar(' ', info);
	}
}

void	print_flags(const char *str, va_list args, t_util *info)
{
	int	pad_len;
	int	zero_pad;

	pad_len = info->width - info->arg_len;
	zero_pad = info->precision - info->arg_len;
	if (zero_pad > 0)
		pad_len -= zero_pad;
	print_prefix(info, str);
	if (pad_len > 0 && !info->left_align && info->zero_fill)
		print_zeros(pad_len, info);
	else if (!info->left_align && pad_len > 0)
		print_spaces(pad_len, info);
	if (zero_pad > 0)
		print_precision(zero_pad, info);
	print_format(str, args, info);
	if (info->left_align && pad_len > 0)
		print_spaces(pad_len, info);
}
