/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboumlik <mboumlik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 02:41:02 by mboumlik          #+#    #+#             */
/*   Updated: 2024/03/26 15:33:47 by mboumlik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int signum)
{
	static char	char_bit;
	static int	i;

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
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	write(1, "pid: ", 5);
	ft_putnbr(pid);
	write(1, "\n", 1);
	signal(SIGUSR1, &handler);
	signal(SIGUSR2, &handler);
	while (1)
	{
	}
	return (0);
}
