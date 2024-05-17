/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djelacik <djelacik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 13:38:32 by djelacik          #+#    #+#             */
/*   Updated: 2024/05/15 16:53:57 by djelacik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	precision_helper(const char **format, t_util *info);

void	get_percision(const char **format, t_util *info)
{
	while (ft_isdigit((int) **format))
	{
		info->precision = info->precision * 10 + (**format - '0');
		(*format)++;
	}
}

void	parse_width(const char **format, t_util *info)
{
	info->width = 0;
	while (ft_isdigit((int)**format))
	{
		info->width = info->width * 10 + (**format - '0');
		(*format)++;
	}
}

void	parse_flags(const char **format, t_util *info)
{
	while (**format == '-' || **format == '0'
		|| **format == '#' || **format == ' ' || **format == '+')
	{
		if (**format == '-')
		{
			info->left_align = 1;
			info->zero_fill = 0;
		}
		else if (**format == '0' && !info->left_align)
			info->zero_fill = 1;
		else if (**format == '#')
			info->hash = 1;
		else if (**format == ' ')
			info->space = 1;
		else if (**format == '+')
		{
			info->plus = 1;
			info->space = 0;
		}
		(*format)++;
	}
	if (**format == '.')
		precision_helper(format, info);
}

static void	precision_helper(const char **format, t_util *info)
{
	(*format)++;
	if (ft_isdigit((int) **format))
		get_percision(format, info);
}
