/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amrakibe <amrakibe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 19:34:12 by amrakibe          #+#    #+#             */
/*   Updated: 2022/03/14 20:50:50 by amrakibe         ###   ########.fr       */
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
int			ft_putchar(char c);
// long long	ft_atoi(const char *nptr);
int			ft_strlen(char *str);
int			ft_atoi(const char *str);
int			ft_isdigit(int c);

#endif
