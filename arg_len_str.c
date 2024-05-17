/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_len_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djelacik <djelacik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 17:10:23 by djelacik          #+#    #+#             */
/*   Updated: 2024/05/15 13:26:49 by djelacik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	arg_len_str(va_list args, t_util *info)
{
	char	*arg;
	va_list	args_copy;

	va_copy(args_copy, args);
	arg = va_arg(args_copy, char *);
	if (arg != NULL)
	{
		info->arg_len = ft_strlen(arg);
	}
	else
	{
		info->arg_len = 0;
	}
	va_end(args_copy);
}
