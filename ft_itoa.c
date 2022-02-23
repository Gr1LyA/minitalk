/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharland <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 15:13:33 by tharland          #+#    #+#             */
/*   Updated: 2021/10/06 15:13:35 by tharland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_putnbr_in_mass(long int n, char	*str, int	*i)
{
	if (n > 9)
		ft_putnbr_in_mass(n / 10, str, i);
	str[*i] = n % 10 + '0';
	(*i)++;
}

static int	ft_len_num(long int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (++i);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			len;
	int			i;
	long int	num;

	i = 0;
	num = (long int)n;
	len = ft_len_num(num);
	str = malloc(sizeof(*str) * (len + 1));
	if (!str)
		return (NULL);
	if (num < 0)
	{
		str[i] = '-';
		i++;
		num *= -1;
	}
	ft_putnbr_in_mass(num, str, &i);
	str[i] = '\0';
	return (str);
}
