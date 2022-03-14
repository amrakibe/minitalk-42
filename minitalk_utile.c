/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utile.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amrakibe <amrakibe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 17:17:13 by amrakibe          #+#    #+#             */
/*   Updated: 2022/03/14 20:50:36 by amrakibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_strlen(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		;
	return (i);
}

// long	long	ft_atoi(const char *nptr)
// {
// 	int			i;
// 	int			signe;
// 	long long	rslt;

// 	i = 0;
// 	signe = 1;
// 	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
// 		i++;
// 	if (nptr[i] == '-' || nptr[i] == '+')
// 	{
// 		if (nptr[i] == '-')
// 			signe *= -1;
// 		i++;
// 	}
// 	while (nptr[i] >= 48 && nptr[i] <= 57)
// 	{
// 		rslt = rslt * 10 + nptr[i] - 48;
// 		i++;
// 	}
// 	return (rslt * signe);
// }

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

void	ft_putnbr(int n)
{
	long	nb;

	nb = n;
	if (n < 0)
	{
		nb *= -1;
		ft_putchar('-');
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putchar(nb % 10 + '0');
	}
	else
		ft_putchar('0' + nb);
}

int	ft_atoi(const char *str)
{
	size_t	i;
	size_t	num;
	size_t	sign;

	num = 0;
	sign = 1;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (ft_isdigit(str[i]) && str[i])
	{
		num *= 10;
		num += str[i] - 48;
		i++;
	}
	return (num * sign);
}

int	ft_isdigit(int c)
{
	if (c < '0' || c > '9')
		return (0);
	return (1);
}
