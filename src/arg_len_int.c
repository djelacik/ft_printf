/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_len_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djelacik <djelacik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:54:47 by djelacik          #+#    #+#             */
/*   Updated: 2024/06/15 12:45:03 by djelacik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_numlen(int n, t_util *info)
{
	unsigned int	len;

	if (n == 0)
		info->int_is_zero = 1;
	len = 1;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		info->int_is_minus = 1;
	}
	while (n >= 10)
	{
		n /= 10;
		len++;
	}
	return (len);
}

void	arg_len_int(va_list args, t_util *info)
{
	int		arg;
	va_list	args_copy;

	va_copy(args_copy, args);
	arg = va_arg(args_copy, int);
	info->arg_len = ft_numlen(arg, info);
	va_end(args_copy);
}
