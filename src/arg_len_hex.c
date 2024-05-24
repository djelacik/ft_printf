/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_len_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djelacik <djelacik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:27:37 by djelacik          #+#    #+#             */
/*   Updated: 2024/05/23 10:14:47 by djelacik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hexlen(unsigned int n, t_util *info)
{
	int	len;

	if (n == 0)
		info->int_is_zero = 1;
	len = 0;
	if (n == 0)
		return (0);
	while (n > 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

void	arg_len_hex(va_list args, t_util *info)
{
	unsigned int	arg;
	va_list			args_copy;

	info->int_is_zero = 0;
	va_copy(args_copy, args);
	arg = va_arg(args_copy, unsigned int);
	info->arg_len = ft_hexlen(arg, info);
	va_end(args_copy);
}
