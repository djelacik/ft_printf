/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djelacik <djelacik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 10:58:49 by djelacik          #+#    #+#             */
/*   Updated: 2024/05/15 17:24:07 by djelacik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_ptr(va_list args, t_util *info)
{
	unsigned long long	ptr;

	ptr = va_arg(args, unsigned long long);
	ft_putstr("0x", info);
	ft_hexa_base((unsigned long long) ptr, "0123456789abcdef", info);
}
