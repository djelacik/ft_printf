/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djelacik <djelacik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 21:49:38 by djelacik          #+#    #+#             */
/*   Updated: 2024/05/15 14:27:37 by djelacik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_str(va_list args, t_util *info)
{
	char	*string;

	string = va_arg(args, char *);
	if (string != NULL)
	{
		ft_putstr(string, info);
	}
	else
	{
		ft_putstr("(null)", info);
	}
}
