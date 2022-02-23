/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharland <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 17:08:18 by tharland          #+#    #+#             */
/*   Updated: 2021/10/06 17:08:20 by tharland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

int		ft_atoi(const char *str);
void	check_pid(char *argv_pid);
size_t	ft_strlen(char *str);
char	*ft_itoa(int n);
void	ft_putnbr(int n);

#endif
