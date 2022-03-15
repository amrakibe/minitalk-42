/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amrakibe <amrakibe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 19:34:12 by amrakibe          #+#    #+#             */
/*   Updated: 2022/03/15 17:04:51 by amrakibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

void		myhandl(int siguser, siginfo_t *list_info, void *on);
void		send(char c, int pid);
void		ft_putnbr(int n);
void		ft_putchar(char c);
int			ft_atoi(const char *str);
int			ft_isdigit(int c);

#endif
