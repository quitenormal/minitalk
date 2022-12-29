/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjirapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 19:01:43 by yjirapin          #+#    #+#             */
/*   Updated: 2022/03/08 20:54:13 by yjirapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/* Take that, moulinette!
The ft_itoa takes a number and return a string that
looks just like the number to the naked eye. But to C they
 are different because C is, well, special.
*/

#include "libft.h"

/* This is a private function, ft_hereisastring, which takes a string and
a number of length (an integer) and returns a string.

The same string is returned if the number is 0.
*/
static char	*ft_hereisastring(char *x, unsigned int number, int len)
{
	while (number > 0)
	{
		x[len] = 48 + (number % 10);
		number = number / 10;
		len--;
	}
	return (x);
}

/* We have strlen to determine the length of a string. However,
in this private function, we have ft_len to tell us the length of
an integer.

There are two cases:

If n is equal to or less than zero, then
	len starts at 1 (becaused we'll need space for the - sign)
As long as n is not null, we'll increment it with each n
that is divisible by ten.
*/

static int	ft_len(int n)
{
	int					len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

/*
The ft_itoa() function coverts the integer n into a character string.
The string is placed in the buffer passed, which must be large enough
 to hold the output. Here we prepare x so that it is big enough using the
 length of the integer passed as input (that we get from ft_len() above).
As usual, for malloc we check for NULL.
Then if the number is really 0, we just make x[0]=0
Then we'll remove the minus sign and make a note of it - if negative value.
Then we'll feed the number to the sandworm .. I mean ..
ft_hereisastring().
Finally, we'll set the last char of x to \0.
*/

char	*ft_itoa(int n)
{
	char				*x;
	int					len;
	unsigned int		number;
	int					sign;

	sign = 1;
	len = ft_len(n);
	x = (char *)malloc(sizeof(char) * (len + 1));
	if (!(x))
		return (NULL);
	if (n == 0)
		x[0] = '0';
	if (n < 0)
	{
		sign *= -1;
		number = n * -1;
		x[0] = '-';
	}
	else
		number = n;
	x = ft_hereisastring(x, number, len - 1);
	x[len] = '\0';
	return (x);
}

/* Some people make len a long int but I see no need because
life is not a mystery to be solved but a mystery to be lived.
*/
