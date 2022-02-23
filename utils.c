/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharland <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 15:14:04 by tharland          #+#    #+#             */
/*   Updated: 2021/10/06 15:14:06 by tharland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	check_pid(char *argv_pid)
{
	while (*argv_pid)
	{
		if (*argv_pid < '0' || *argv_pid > '9')
		{
			write(1, "Error\n", 6);
			exit (0);
		}
		argv_pid++;
	}
}

int	ft_atoi(const char *str)
{
	int	res;
	int	znak;

	znak = 1;
	res = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
	{
		znak *= -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9' && *str != '\0')
	{
		res = res * 10 + *str - 48;
		str++;
	}
	return (res * znak);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putnbr(int n)
{
	char	symbol;

	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
	}
	if (n > 9)
		ft_putnbr(n / 10);
	symbol = 48 + n % 10;
	write(1, &symbol, 1);
}
