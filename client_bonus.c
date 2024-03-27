/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboumlik <mboumlik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:42:51 by mboumlik          #+#    #+#             */
/*   Updated: 2024/03/27 13:38:58 by mboumlik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	get_bet(int pid, char ch)
{
	int	shift;

	shift = 7;
	while (shift >= 0)
	{
		if ((ch >> shift) & 1)
		{
			kill(pid, SIGUSR1);
		}
		else
		{
			kill(pid, SIGUSR2);
		}
		shift--;
		usleep(150);
	}
}

void	send_bit(int pid, char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		get_bet(pid, str[i]);
		i++;
	}
	get_bet(pid, str[i]);
}

void	msg_sent(void)
{
	write(1, "your msg is sent!!", 19);
}

int	main(int ac, char *av[])
{
	int		pid;
	char	*str;
	int		i;

	i = 0;
	signal(SIGUSR1, msg_sent);
	if (ac == 3)
	{
		while (av[1][i])
		{
			if (!ft_isdigit(av[1][i]))
			{
				write(1, "dont put a letter inside the pid", 33);
			}
			i++;
		}
		pid = ft_atoi(av[1]);
		str = av[2];
		send_bit(pid, str);
	}
	else
		write(1, "only 3 arguments", 17);
}
