/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_len_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djelacik <djelacik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:54:47 by djelacik          #+#    #+#             */
/*   Updated: 2024/05/15 13:26:16 by djelacik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_numlen(int n)
{
	unsigned int	len;

	len = 1;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		len++;
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
	if (arg != 0)
	{
		info->arg_len = ft_numlen(arg);
	}
	else
	{
		info->arg_len = 0;
	}
	va_end(args_copy);
}
