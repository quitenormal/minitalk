/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjirapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 20:31:59 by yjirapin          #+#    #+#             */
/*   Updated: 2022/03/06 19:52:58 by yjirapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/*****
the memcmp function returns a negative, zero, or positive integer
depending on whether the first n characters of the object pointed to by ptr1
are less than, equal to, or greater than the first n characters
of the object pointed to by ptr2.

ptr1 − This is the pointer to a block of memory.
ptr2 − This is the pointer to a block of memory.
n − This is the number of bytes to be compared.

if Return value < 0 then it indicates ptr1 is less than ptr2.
if Return value > 0 then it indicates ptr2 is less than ptr1.
if Return value = 0 then it indicates ptr1 is equal to ptr2.

I had to use:
	const unsigned char	*mystr1;
	const unsigned char	*mystr2;
Otherwise I will get:
	error: assignment discards ‘const’ qualifier from pointer target type

But I didn't have to USE these two lines?
	//mystr1 = (const unsigned char *)ptr1;
	//mystr2 = (const unsigned char *)ptr2;
*/

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t n)
{
	const unsigned char	*mystr1;
	const unsigned char	*mystr2;
	size_t				i;

	i = 0;
	mystr1 = ptr1;
	mystr2 = ptr2;
	while (i < n)
	{
		if (mystr1[i] != mystr2[i])
			return (mystr1[i] - mystr2[i]);
		i++;
	}
	return (0);
}

/*----------------------------------------------------------------
Main for checking


#include <string.h>
#include <stdio.h>

int main () {
   char str1[15];
   char str2[15];
   int ret;

  // memcpy(str1, "ZAbcdef", 7);
  // memcpy(str2, "ZaBCDEF", 7);

 memcpy(str1, "ZAAAAAA", 7);
 memcpy(str2, "ZAAAAAA", 7);

  ret = memcmp(str1, str2, 5);

   if(ret > 0) {
      printf("str2 is less than str1\n");
   } else if(ret < 0) {
      printf("str1 is less than str2\n");
   } else {
      printf("str1 is equal to str2\n");
   }

  ret = ft_memcmp(str1, str2, 5);

   if(ret > 0) {
      printf("ft: str2 is less than str1\n");
   } else if(ret < 0) {
      printf("ft: str1 is less than str2\n");
   } else {
      printf("ft: str1 is equal to str2\n");
   }

   return(0);
}

*/
