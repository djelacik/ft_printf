/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djelacik <djelacik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 10:31:27 by djelacik          #+#    #+#             */
/*   Updated: 2024/05/15 16:53:07 by djelacik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_format(const char **format, t_util *info)
{
	if (ft_isdigit((int)**format))
		parse_width(format, info);
	parse_flags(format, info);
	if (ft_isdigit((int)**format))
		parse_width(format, info);
}
