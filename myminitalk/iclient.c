/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iclient.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjirapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 20:11:12 by yjirapin          #+#    #+#             */
/*   Updated: 2022/12/29 15:04:32 by yjirapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include "libft.h"
#include <stdlib.h>

//send bit .. either 1 or 0
//decides to send SIGUSR1 if 1
int	send_bit(char bit, int pid)
{
	if (bit)
	{
		if (kill (pid, SIGUSR1) == -1)
			exit (0);
	}
	else
	{
		if (kill (pid, SIGUSR2) == -1)
			exit (0);
	}
	usleep (333);
	return (1);
}

//Prep_char
//By casting the char to an integer, you'll get the ascii value.

void	prep_char(int character, int pid)
{
	int	quotient;
	int	oneorzero;
	int	compensate;

	compensate = 0;
	quotient = character;
	while (quotient > 0)
	{
		compensate++;
		oneorzero = quotient % 2;
		quotient = quotient / 2;
		send_bit(oneorzero, pid);
		usleep (555);
	}
	while (7 - compensate > 0)
	{
		send_bit(0, pid);
		compensate++;
	}
}

int	main(int argc, char **argv)
{
	char	*str;
	int		server_pid;
	int		k;

	if (argc < 3)
		exit (0);
	server_pid = ft_atoi(argv[1]);
	if (server_pid <= 0 || kill(server_pid, 0) < 0)
	{
		ft_putendl_fd("Invalid Process ID.\n", 1);
		return (0);
	}
	str = argv[2];
	if (!str)
	{
		ft_putendl_fd("Empty String.\n", 1);
		return (0);
	}
	k = 0;
	while (str[k])
	{
		prep_char(str[k], server_pid);
		k++;
	}
	return (0);
}
