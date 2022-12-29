/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjirapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 07:30:52 by yjirapin          #+#    #+#             */
/*   Updated: 2022/03/04 07:56:35 by yjirapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/*In computer programming, the strlcpy function is intended to replace
the function strcpy (which copies a string to a destination buffer)
with a secure version that cannot overflow the destination buffer.
It is almost always accompanied by the strlcat function
which provides a similar alternative to strcat
(which appends a source string to a destination buffer).
strlcpy will pad dest with /0 for the destsize specified

Note: strlcpy will return a length of source if destsize is 0

ft_strcpy.c looks like this:
char *ft_strcpy(char *dest, char *src)
{   int i;
	i = 0;
	while (src[i])
	{dest[i] = src[i];
		i++;}
	dest[i] = '\0';
	return (dest);}
*/

size_t	ft_strlcpy(char *dest, const char *src, size_t destsize)
{
	size_t	i;

	i = 0;
	if (destsize == 0)
	{
		while (src[i])
			i++;
		return (i);
	}
	while (i < destsize - 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	if (i < destsize)
		dest[i] = '\0';
	while (src[i])
		i++;
	return (i);
}
