/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djelacik <djelacik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 18:13:36 by djelacik          #+#    #+#             */
/*   Updated: 2024/05/15 17:23:03 by djelacik         ###   ########.fr       */
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
	return (str_util.total);
}

// #include <limits.h>
// int	main(void)
// {
// 	printf("Mine%d\n", (printf("Mine%d\n",printf("%p\n", (void *)25))));
// 	//my_printf("Hello, %c! This is a %%s example.\n", 'W');
// 	printf("OG%d\n", (printf("Real:%d",ft_printf("%p\n", (void *)25))));

// 	//printf("Mine%d\n",printf(" %-11p %-12p ", (void *)INT_MIN, (void *)INT_MAX));
// 	//my_printf("Hello, %c! This is a %%s example.\n", 'W');
// 	//printf("Real:%d",ft_printf(" %-11p %-12p ", (void *)INT_MIN, (void *)INT_MAX));
// 	//ft_printf("First number: %c Second number %c\n", 'a', 'b');
// 	return (0);
// }