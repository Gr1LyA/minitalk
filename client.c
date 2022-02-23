/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharland <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 16:01:00 by tharland          #+#    #+#             */
/*   Updated: 2021/10/06 16:01:01 by tharland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <signal.h>
#include <unistd.h>
#include <stdio.h>

void	to_binary(unsigned char message, char *symbol)
{
	int	i;

	i = 7;
	while (message > 0)
	{
		symbol[i] = message % 2 + 48;
		message /= 2;
		i--;
	}
	while (i >= 0)
	{
		symbol[i] = '0';
		i--;
	}
}

void	send_bit(pid_t pid, char *message)
{
	int		i;
	int		j;
	int		len;
	char	*symbol;

	i = 0;
	len = ft_strlen(message);
	symbol = malloc(9);
	symbol[8] = '\0';
	while (i <= len)
	{
		to_binary((unsigned char)message[i], symbol);
		j = 0;
		while (symbol[j])
		{
			if (symbol[j] == '0')
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(80);
			j++;
		}
		i++;
	}
	free(symbol);
}

int	main(int argc, char **argv)
{
	pid_t				pid;

	if (argc != 3)
	{
		write(1, "Error\n", 6);
		exit (0);
	}
	check_pid(argv[1]);
	pid = ft_atoi(argv[1]);
	send_bit(pid, argv[2]);
	return (0);
}
