/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjirapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 22:16:54 by yjirapin          #+#    #+#             */
/*   Updated: 2022/03/13 14:24:24 by yjirapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putendl_fd(char const *s, int fd)
{
	int		i;
	char	c;

	c = '\n';
	if (s)
	{
		i = 0;
		while (s[i])
		{
			write(fd, &s[i], 1);
			i++;
		}
	}
	write(fd, &c, 1);
}

/* Dev notes
The write command needs a pointer as a second argument or a char 'x' where x is
any character. In this case, &s[i] is the pointer to s[i]. & means
the address-of, you will see that in placeholders for functions to
modify the parameter variable.
*/
