/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboumlik <mboumlik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 02:41:05 by mboumlik          #+#    #+#             */
/*   Updated: 2024/03/27 13:35:50 by mboumlik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_bit_to_server(int pid, char *str)
{
	size_t	i;
	int		j;

	i = 0;
	while (str[i])
	{
		j = 7;
		while (j >= 0)
		{
			if ((str[i] >> j) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(150);
			j--;
		}
		i++;
	}
}

int	main(int ac, char *av[])
{
	int		pid;
	char	*str;
	int		i;

	i = 0;
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
		send_bit_to_server(pid, str);
	}
	else
		write(1, "only 3 arguments", 17);
}
