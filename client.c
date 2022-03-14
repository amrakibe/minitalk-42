/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amrakibe <amrakibe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 17:09:00 by amrakibe          #+#    #+#             */
/*   Updated: 2022/03/14 21:03:52 by amrakibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send(char c, int pid)
{
	int	i;
	int	bit;
	int	ckill;

	i = 7;
	while (i >= 0)
	{
		bit = (c >> i) & 1;
		ckill = kill(pid, SIGUSR1 + bit);
		if (ckill == -1)
		{
			write(1, "pid is incorrect", 17);
			exit(1);
		}
		usleep(800);
		i--;
	}
}

int	main(int ac, char **av)
{
	int	i;
	int	pid;

	i = 0;
	if (ac != 3)
	{
		write(1, "invalid arguments", 18);
		exit(EXIT_FAILURE);
	}
	pid = ft_atoi(av[1]);
	if (pid < 1)
	{
		write(1, "invalid pid", 12);
		exit(EXIT_FAILURE);
	}
	while (av[2][i])
		send(av[2][i++], pid);
}
