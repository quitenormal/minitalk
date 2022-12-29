/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iserver.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjirapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 20:11:21 by yjirapin          #+#    #+#             */
/*   Updated: 2022/12/29 15:17:35 by yjirapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//include stuff
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include "libft.h"

typedef struct s_total
{
	int		count;
	char	newbyte;
}	t_total;

t_total	g_g = {0, 0};
/*
The original ASCII was a 7 bit character set
(128 possible characters) with no accented letters.
This was used in teletype machines.
(The eighth bit was originally used to check parity - a way to look for errors.)
*/
//main
//1. Print PID (Done)
//2. Wait for signal with handler (Done)
//3. Print the string (Done)
// - Break it into bytes
// - Print each char
//4. Handle error

//printing the pid to stdout
void	print_pid(void)
{
	ft_putendl_fd("pid: ", 1);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
}

void	byteme(int bitvalue)
{
	g_g.newbyte = g_g.newbyte + (bitvalue << g_g.count);
	g_g.count++;
	if (g_g.count == 7)
	{
		write(1, &g_g.newbyte, 1);
		g_g.count = 0;
		g_g.newbyte = 0;
	}
	return ;
}

//handler
//Return type of the handler function should be void
void	sig_handler(int signum)
{
	if (signum == SIGUSR1)
	{
		byteme(1);
	}
	if (signum == SIGUSR2)
	{
		byteme(0);
	}
}

int	main(void)
{
	print_pid();
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	while (1)
	{
		usleep (100);
	}
	return (0);
}
