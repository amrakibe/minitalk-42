/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amrakibe <amrakibe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 17:08:22 by amrakibe          #+#    #+#             */
/*   Updated: 2022/03/15 16:20:37 by amrakibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	myhandl(int siguser, siginfo_t *info, void *no)
{
	static char	c;
	static int	i;
	static int	client_pid;

	(void)no;
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
		write(1, &c, 1);
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
/*
If SA_SIGINFO is specified in sa_flags, then sa_sigaction (instead of sa_handler) specifies the signal-handling function for signum. This function receives the signal number as its first argument, a pointer to a siginfo_t as its second argument and a pointer to a ucontext_t (cast to void *) as its third argument
*/
	sigaction(SIGUSR1, &a, NULL);
	sigaction(SIGUSR2, &a, NULL);
	write(1,"pid is => ",11);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	while (1)
		pause();
}
