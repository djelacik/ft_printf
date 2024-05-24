/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djelacik <djelacik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 09:43:35 by djelacik          #+#    #+#             */
/*   Updated: 2024/05/23 14:40:34 by djelacik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_int(va_list args, t_util *info)
{
	int	value;

	value = va_arg(args, int);
	if (info->int_is_minus && info->precision_active)
		value *= -1;
	ft_putnbr(value, info);
}
