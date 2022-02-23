/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharland <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 16:01:07 by tharland          #+#    #+#             */
/*   Updated: 2021/10/06 16:01:09 by tharland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_handler(int bit, siginfo_t *siginfo, void *context)
{
	static char	symbol;
	static char	i;

	context = 0;
	siginfo = 0;
	if (bit == SIGUSR2)
		symbol |= (1 << (7 - i));
	i++;
	if (i == 8)
	{
		i = 0;
		if (!symbol)
			write(1, "\n", 1);
		else
			write(1, &symbol, 1);
		symbol = 0;
	}
}

int	main(int argc, char **argv)
{
	pid_t				pid;
	struct sigaction	sigact;

	sigact.sa_flags = SA_SIGINFO;
	sigact.sa_sigaction = ft_handler;
	sigaction(SIGUSR1, &sigact, NULL);
	sigaction(SIGUSR2, &sigact, NULL);
	argv = NULL;
	pid = getpid();
	if (argc != 1)
		write(1, "Error\n", 6);
	else
	{
		ft_putnbr(pid);
		write(1, "\n", 1);
		while (1)
			pause();
	}
	return (0);
}
