/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjirapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 14:26:52 by yjirapin          #+#    #+#             */
/*   Updated: 2022/03/13 18:29:14 by yjirapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ft_striteri takes a string and a pointer to a destination function.
It will iterate over i for any destination function that
takes an unsigned integer and a string. The destination function is identified
by the pointer passed as the second argument to ft_striteri.
The call to the destination function is made at the line f(i, &s[i]) where
each character (or rather the pointer to each charcter) is passed
to the destination function along with the index one by one.
*/

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

/* Dev's notes:
In computing. The number 4,294,967,295,
equivalent to the hexadecimal value FFFF,FFFF16, is the maximum value
for a 32-bit unsigned integer in computing.
*/
