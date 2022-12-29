/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjirapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 19:54:04 by yjirapin          #+#    #+#             */
/*   Updated: 2022/03/05 06:35:41 by yjirapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

// ft_memchr
// syntax: void *ft_memchr(const void *str, int c, size_t n)

// str − This is the pointer to the block of memory
// where the search is performed.
// c − This is the value to be passed as an int,
//	but the function performs a byte per byte search
// using the unsigned char conversion of this value.
// n − This is the number of bytes to be analyzed.
// This function returns a pointer to the matching byte or NULL
//	   if the character does not occur in the given memory area.

void	*ft_memchr(const void *solana, int coinbase, size_t n)
{
	size_t			icecream;
	unsigned char	*sandwich;
	unsigned char	cocoa;

	sandwich = (unsigned char *)solana;
	cocoa = (unsigned char)coinbase;
	icecream = 0;
	while (icecream < n)
	{
		if (*sandwich == cocoa)
		{
			return (sandwich);
		}
		sandwich++;
		icecream++;
	}
	return (NULL);
}

/*******************************
compare with real memchr
Results: Only the last scenario will get segmentation fault
for both memchr and ft_memchr
Note: Need to run em one by one (comment out the rest)

#include <string.h>
#include <stdio.h>

int	main(void) {

	char *realstr;
	char *mimicstr;
	char *results;

	realstr = memchr("I have terrible news. We won.", '.', 100);
	mimicstr = ft_memchr("I have terrible news. We won.", '.', 100);
	puts(realstr);
	puts(mimicstr);
	printf("Compare results: %d\n",(strcmp(realstr,mimicstr)));

	realstr = memchr("x.xxxxx.x", '.', 10);
	mimicstr = ft_memchr("x.xxxxx.x", '.', 10);
	puts(realstr);
	puts(mimicstr);
	printf("Compare results: %d\n",(strcmp(realstr,mimicstr)));

	realstr = memchr("x.xxxxx.x", '.', 4);
	mimicstr = ft_memchr("x.xxxxx.x", '.', 4);
	puts(realstr);
	puts(mimicstr);
	printf("Compare results: %d\n",(strcmp(realstr,mimicstr)));

	realstr = memchr(".xxxxx.x", '.', 1);
	mimicstr = ft_memchr(".xxxxx.x", '.', 1);
	puts(realstr);
	puts(mimicstr);
	printf("Compare results: %d\n",(strcmp(realstr,mimicstr)));

	realstr = memchr(".xxxxx.x", '.', -1);
	mimicstr = ft_memchr(".xxxxx.x", '.', -1);
	puts(realstr);
	puts(mimicstr);
	printf("Compare results: %d\n",(strcmp(realstr,mimicstr)));

	realstr = memchr("xxxxxx.x", '.', 4);
	mimicstr = ft_memchr("xxxxxx.x", '.', 4);
	puts(realstr);
	puts(mimicstr);
	printf("Compare results: %d\n",(strcmp(realstr,mimicstr)));

	return(0);
}
*/
