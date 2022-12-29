/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjirapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 01:32:06 by yjirapin          #+#    #+#             */
/*   Updated: 2022/03/11 14:27:02 by yjirapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The ft_strchr() function returns a pointer to the first occurrence
 of the character c in the string s.
*/

char	*ft_strchr(const char *s, int c)
{
	char	*newstr;

	newstr = (char *)s;
	while (*newstr != (unsigned char)c)
	{
		if (*newstr == '\0')
		{
			return (0);
		}
		newstr++;
	}
	return (newstr);
}

/* Dev notes: Once upon a time, there was a function named ft_strchr.
It takes a string and a character.

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;

The internal str is equal to s but not a const.
As long as each character is not a c.
The pointer of str moves forward.
The pointer to the place where C is found (or rather the remainder
of the string where C is found) is returned.
If C is never found, then 0 is returned once the pointer
reaches the end of the string.

	while (*str != c)
	{
		if (*str == '\0')
		{
			return (0);
		}
		str++;
	}
	return (str);
}

*/

/* Main function for testing

#include <unistd.h>
#include <stdio.h>

int main (void) {
	char * thisstr;

	thisstr = ft_strchr(" .?,",'?');
	printf("The answer is %s \n",thisstr);
	thisstr = ft_strchr(" .?,",'.');
	printf("The answer is %s \n",thisstr);
	thisstr = ft_strchr(" .?,",'c');
	printf("The answer is %s \n",thisstr);
}
*/
