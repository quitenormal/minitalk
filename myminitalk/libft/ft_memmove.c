/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjirapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 15:21:47 by yjirapin          #+#    #+#             */
/*   Updated: 2022/03/16 15:29:17 by yjirapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/* ft_memmove() is used to copy a block of memory from a location to another.
ft_memcpy() simply copies data one by one from one location to another.
On the other hand ft_memmove() copies the data first to an intermediate buffer,
then from the buffer to destination.
ft_memcpy() leads to problems when strings overlap.
Copies "numBytes" bytes from address "from" to address "to"

void * ft_memmove(void *to, const void *from, size_t numBytes);

Ex1: char sentence[100] = "GeeksforPresident";
    ft_memmove(sentence + 5, sentence, strlen(sentence) + 1);
	Results: Geeksfor > GeeksGeeksforPresident

Ex2:char x[50] = "Your mother bode you obey me."
	char y[50] = "Do you know what is in the box?"
	ft_memmove(y,x,16);
	Results: x is the same as before
	and y = Your mother bode is in the box.

High-level design:
I. If paul (dest) or chani (src) is null then return null
II. If chani < paul that means that Chani occupies the address space
that is lower than paul. then from the start location
	- make paul (dest) be chani (src)
	- one by one starting from n and as i increases the index will be decreasing
	 with (n - i) as long as it is not more than n.
	- this way the end of paul is populated with the end of chani first
so that if paul's first character overflows into chani we would still get
a few of the characters from the far end.
III. Otherwise paul is > chani which means paul occupies the address space
after Chani.
	- as i approaches n, make paul pointer (dest) be chani pointer (src)
	- since chani is const this would change paul not chani

Special cases:
If Paul = Chani then Paul will be equal to Chani .. The end.
If n = 0, then Paul stays the same. Nothing is moved .. The end.

Cool code tricks:
while(++i <= n) - Loop over i as i increases by 1
				- exits when i > n
while(n-->0) - Loop over n in each loop as n decreases by 1
             - exits when n = 0
++i is equivalent to i = i + 1 . i++ and ++i are very similar
but not exactly the same. Both increment the number,
but ++i increments the number before the current expression is evaluated,
whereas i++ increments the number after the expression is evaluated.
*/

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*paul;
	const unsigned char	*chani;

	paul = (unsigned char *)dest;
	chani = (unsigned char *)src;
	i = 0;
	if (!paul && !chani)
		return (NULL);
	if (chani < paul)
		while (++i <= n)
			paul[n - i] = chani[n - i];
	else
		while (n-- > 0)
			*(paul++) = *(chani++);
	return (dest);
}

/* Main function needs the packages below
as well as the ft_memcpy.c to compare results

#include <stdio.h>
#include <string.h>

void		*ft_memcpy(void *dst, const void *src, size_t n);

int main(void) {
	char x[50] = "Your mother bode you obey me.";
	char y[50] = "Do you know what is in the box?";
	ft_memmove(y,x,16);
	puts(x);
	puts(y);

	char sentence1[100] = "GeeksforPresident";
    ft_memmove(sentence1 + 5, sentence1, strlen(sentence1) + 1);
	puts(sentence1);
	char sentence2[100] = "GeeksforVicePresident";
    ft_memcpy(sentence2 + 5, sentence2, strlen(sentence2) + 1);
	puts(sentence2);
	char sentence3[100] = "GeeksforSecretaryofState";
	memmove(sentence3 + 5, sentence3, strlen(sentence3) + 1);
	puts(sentence3);

	char str1[50] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char str2[50] = "xxxxxxx";
	puts(memmove(str1,str2,16));
	puts(ft_memmove(str1,str2,16));
	return(0);
}

*/
