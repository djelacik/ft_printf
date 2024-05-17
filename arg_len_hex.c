/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_len_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djelacik <djelacik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:27:37 by djelacik          #+#    #+#             */
/*   Updated: 2024/05/15 13:25:11 by djelacik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hexlen(unsigned int n)
{
	int	len;

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

	va_copy(args_copy, args);
	arg = va_arg(args_copy, unsigned int);
	if (arg != 0)
	{
		info->arg_len = ft_hexlen(arg);
	}
	else
	{
		info->arg_len = 0;
	}
	va_end(args_copy);
}
