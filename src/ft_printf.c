/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djelacik <djelacik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 18:13:36 by djelacik          #+#    #+#             */
/*   Updated: 2024/05/24 10:58:23 by djelacik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_format(const char *str, va_list args, t_util *str_util)
{
	if (*str == 's')
		print_str(args, str_util);
	else if (*str == 'c')
		print_char(args, str_util);
	else if (*str == 'p')
		print_ptr(args, str_util);
	else if (*str == 'x')
		print_hex_lower(args, str_util);
	else if (*str == 'X')
		print_hex_upper(args, str_util);
	else if (*str == 'd' || *str == 'i')
		print_int(args, str_util);
	else if (*str == 'u')
		print_uns_int(args, str_util);
	else if (*str == '%')
		ft_putchar('%', str_util);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	t_util	str_util;

	ft_bzero(&str_util, sizeof(t_util));
	str_util.flag = 1;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			process_arg_len(format, args, &str_util);
			parse_format(&format, &str_util);
			print_flags(format, args, &str_util);
		}
		else
			ft_putchar(*format, &str_util);
		if (*format)
			format++;
	}
	va_end(args);
	if (str_util.flag == -1)
		return (-1);
	return (str_util.total);
}
#include <libc.h>
int main()
{
    ft_printf("Hello, %s!\n", "world");

    int number = -42;

    ft_printf("Default: %d\n", number);
    ft_printf("Plus flag: %+d\n", number);
    ft_printf("Space flag: % d\n", number);
    ft_printf("Zero padding: %010d\n", number);
    ft_printf("Left-justify with space padding: %-10dEnd\n", number);
    ft_printf("Alternate form (hex): %#x\n", number);
    ft_printf("Multiple flags: %4.8d\n", number);
    return 0;
}