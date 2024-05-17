/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uns_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djelacik <djelacik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:11:52 by djelacik          #+#    #+#             */
/*   Updated: 2024/05/08 11:29:38 by djelacik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_uns_int(va_list args, t_util *info)
{
	unsigned int	value;

	value = va_arg(args, unsigned int);
	ft_put_uns_nbr(value, info);
}
