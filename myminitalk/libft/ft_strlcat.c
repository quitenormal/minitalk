/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjirapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 07:57:20 by yjirapin          #+#    #+#             */
/*   Updated: 2022/03/07 19:53:02 by yjirapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strlen(char *str);

/*
The strlcat() function appends the NUL-terminated string src to the end of dst.
It will append at most size − strlen(dst) − 1 bytes, NUL-terminating the result.

The if (size specified <= size of destination) then it will return
the size of src + the user-specified size to signify that it can not be appended
to the specified size.

Otherwise, it will start with the while loop where i starts at 0.
As long as since of dst plus i is less than specified size - 1
(to leave room for the '\0'), the new dst[current size + i] will
be populated with src[i]. That is to say src will be appended to dst
until src ends.

*/

size_t	ft_strlcat(char *dst, char *src, size_t size)
{
	size_t		i;
	size_t		d_size;
	size_t		s_size;

	d_size = ft_strlen(dst);
	s_size = ft_strlen(src);
	if (size <= d_size)
		return (s_size + size);
	i = 0;
	while (src[i] && (d_size + i) < (size - 1))
	{
		dst[d_size + i] = src[i];
		i++;
	}
	dst[d_size + i] = '\0';
	return (d_size + s_size);
}

/*
Main function to test
The answer is 52 - no matter how much longer mystr(dst) is
(as long as size of mystr is longer than 5 and 10)
The answer is the size of both strings when mystr is less than 30.

#include <stdio.h>
#include <bsd/string.h>

int main(void){
	char *mystr1;
	char *yourstr1;

	mystr1 = "Fear is the mind killer."; //24
	yourstr1 = "Luke, I am your father and this is your mother."; //47

	printf("Expected answer when n = 5: %ld\n", strlcat(mystr1,yourstr1,5));
	printf("Actual answer when n = 5: %ld\n", ft_strlcat(mystr1,yourstr1,5));
// You get 52
	char *mystr2;
	char *yourstr2;

	mystr2 = "Fear is the mind killer."; //24
	yourstr2 = "Luke, I am your father and this is your mother."; //47

	printf("Expected answer when n = 10: %ld\n", strlcat(mystr2,yourstr2,10));
	printf("Actual answer when n = 10: %ld\n", ft_strlcat(mystr2,yourstr2,10));
// You get 57
	return(0);
}
*/
