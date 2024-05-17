/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djelacik <djelacik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:34:04 by djelacik          #+#    #+#             */
/*   Updated: 2024/05/15 17:14:11 by djelacik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, t_util *info)
{
	if (info->flag == -1)
		return ;
	if (write(1, &c, 1) == -1)
		info->flag = -1;
	info->total++;
}

void	ft_putstr(char *s, t_util *info)
{
	while (*s)
		ft_putchar(*s++, info);
}

void	ft_hexa_base(unsigned long long nbr, char *base, t_util *info)
{
	unsigned long long	base_length;

	base_length = 16;
	if (nbr >= base_length)
	{
		ft_hexa_base(nbr / base_length, base, info);
	}
	ft_putchar(base[nbr % base_length], info);
}

void	ft_putnbr(int nb, t_util *info)
{
	char	x;

	if (nb == -2147483648)
	{
		ft_putstr("-2147483648", info);
		return ;
	}
	if (nb < 0)
	{
		ft_putchar('-', info);
		nb *= -1;
	}
	if (nb < 10)
	{
		x = nb + '0';
		ft_putchar(x, info);
	}
	else
	{
		ft_putnbr(nb / 10, info);
		x = (nb % 10) + '0';
		ft_putchar(x, info);
	}
}

void	ft_put_uns_nbr(unsigned int nb, t_util *info)
{
	char	x;

	if (nb < 10)
	{
		x = nb + '0';
		ft_putchar(x, info);
	}
	else
	{
		ft_putnbr(nb / 10, info);
		x = (nb % 10) + '0';
		ft_putchar(x, info);
	}
}
