/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_lower.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djelacik <djelacik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:42:44 by djelacik          #+#    #+#             */
/*   Updated: 2024/05/15 16:54:30 by djelacik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_hex_lower(va_list args, t_util *info)
{
	unsigned int	value;

	value = va_arg(args, unsigned int);
	ft_hexa_base(value, "0123456789abcdef", info);
}
