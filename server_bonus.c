/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amrakibe <amrakibe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 21:19:04 by amrakibe          #+#    #+#             */
/*   Updated: 2022/03/15 16:22:10 by amrakibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	myhandl(int siguser, siginfo_t *info, void *on)
{
	static char	c;
	static int	i;
	static int	client_pid;

	(void)on;
	if (client_pid != 0 && client_pid != info->si_pid)
	{
		write(1, "\n", 1);
		i = 0;
		c = 0;
	}
	c = (c << 1) | (siguser & 1);
	i++;
	if (i == 8)
	{
		if (c == '\0')
			kill(info->si_pid, SIGUSR1);
		else
		{
			write(1, &c, 1);
		}
		c = 0;
		i = 0;
	}
	client_pid = info->si_pid;
}

int	main(void)
{
	struct sigaction	a;

	a.sa_sigaction = &myhandl;
	a.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &a, NULL);
	sigaction(SIGUSR2, &a, NULL);
	write(1,"Pid is => ",11);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	while (1)
		pause();
}
