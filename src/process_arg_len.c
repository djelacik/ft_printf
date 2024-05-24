/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_format_string.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djelacik <djelacik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:20:24 by djelacik          #+#    #+#             */
/*   Updated: 2024/05/15 16:31:30 by djelacik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_skip_flags(const char **s)
{
	while (**s == '-' || **s == '0' || **s == '.'
		|| **s == '#' || **s == ' ' || **s == '+')
		(*s)++;
	while (ft_isdigit(**s))
		(*s)++;
	if (**s == '.')
		(*s)++;
	while (ft_isdigit(**s))
		(*s)++;
}

void	process_arg_len(const char *s, va_list args, t_util *info)
{
	va_list	args_copy;

	va_copy(args_copy, args);
	ft_skip_flags(&s);
	if (*s == 'c')
		info->arg_len = 1;
	else if (*s == 's')
		arg_len_str(args_copy, info);
	else if (*s == 'p')
		info->arg_len = 16 + 2;
	else if (*s == 'x')
		arg_len_hex(args_copy, info);
	else if (*s == 'X')
		arg_len_hex(args_copy, info);
	else if (*s == 'd' || *s == 'i')
		arg_len_int(args_copy, info);
	else if (*s == 'u')
		arg_len_int(args_copy, info);
	else if (*s == '%')
		info->arg_len = 1;
	va_end(args_copy);
}
