/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amrakibe <amrakibe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 20:59:17 by amrakibe          #+#    #+#             */
/*   Updated: 2022/03/15 16:23:57 by amrakibe         ###   ########.fr       */
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
			write(1, "pid is incorrect\n", 17);
			exit(1);
		}
		usleep(800);
		i--;
	}
}

void	handler(int i)
{
	(void) i;
	write(1, "success send\n", 14);
}

int	main(int ac, char **av)
{
	int	i;
	int	pid;

	i = 0;
	signal(SIGUSR1, &handler);
	if (ac != 3)
	{
		write(1, "invalid arguments\n", 18);
		exit(1);
	}
	pid = ft_atoi(av[1]);
	if (pid < 1)
	{
		write(1, "invalid pid\n", 13);
		exit(1);
	}
	while (av[2][i])
		send(av[2][i++], pid);
	send('\0', pid);
	return (0);
}
