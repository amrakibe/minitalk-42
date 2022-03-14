/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amrakibe <amrakibe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 17:09:00 by amrakibe          #+#    #+#             */
/*   Updated: 2022/03/14 17:55:17 by amrakibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send(char c, int pid)
{
	int i = 7;
	while(i >= 0)
	{
		int bit = (c >> i) & 1;
		int ckill;
		ckill= kill(pid, SIGUSR1 + bit);
		if(ckill == -1)
		{
			write(1, "the pid is wrong",17);
			exit(1);
		}
		usleep(800);
		i--;
	}
}
int main(int ac, char **av)
{
	int i = 0;
	if(ac != 3)
	{
		write(1, "Error In Pid" ,14);
		exit(EXIT_FAILURE);
	}
	
	int pid = atoi(av[1]);
	if(pid < 1)
	{
		write(1, "error in pid", 13);
		exit(EXIT_FAILURE);
	}
	while(av[2][i])
		send(av[2][i++], pid); 
}
