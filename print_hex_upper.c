/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_upper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djelacik <djelacik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 09:16:52 by djelacik          #+#    #+#             */
/*   Updated: 2024/05/15 14:38:49 by djelacik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_hex_upper(va_list args, t_util *info)
{
	unsigned int	value;

	value = va_arg(args, unsigned int);
	ft_hexa_base(value, "0123456789ABCDEF", info);
}
