# ifndef MINITALK_H
#define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <stdio.h>

void myhandl(int siguser, siginfo_t *list_info, void *on);
void send(char c, int pid);
void	ft_putnbr(int n);
int	ft_putchar(char c);
long	long	ft_atoi(const char *nptr);
int	ft_strlen(char *str);

#endif