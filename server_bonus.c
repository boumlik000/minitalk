/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboumlik <mboumlik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:13:50 by mboumlik          #+#    #+#             */
/*   Updated: 2024/03/27 12:15:17 by mboumlik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int signum, siginfo_t *info, void *context)
{
	static char	char_bit;
	static int	i;

	(void)context;
	char_bit = char_bit << 1;
	if (signum == SIGUSR1)
		char_bit++;
	i++;
	if (char_bit && i > 7)
	{
		write(1, &char_bit, 1);
		char_bit = 0;
		i = 0;
	}
	else if (!char_bit && i > 7)
	{
		write(1, "\n", 1);
		char_bit = 0;
		i = 0;
		kill(info->si_pid, SIGUSR1);
	}
}

int	main(void)
{
	struct sigaction	sa;
	int					pid;

	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	pid = getpid();
	write(1, "pid_bonus_server: ", 19);
	ft_putnbr(pid);
	write(1, "\n", 1);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		usleep(0);
	}
	return (0);
}
