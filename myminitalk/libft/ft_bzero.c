/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjirapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 23:56:57 by yjirapin          #+#    #+#             */
/*   Updated: 2022/03/07 19:52:02 by yjirapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/*
What does ft_bzero do?
The bzero function can be used to erase the given memory area
 with zero bytes (\0). It takes two arguments, the starting address
  of the memory region and the number of bytes that need to be zeroed out.
*/

void	ft_bzero(void *someaddress, size_t n)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = (char *)someaddress;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}

/*
Main function for testing
Observation: Using n = -1, ft_bzero does not give a warning during comilation.
This is not good because it can result in unpredictable behavior.
bzero.c gives a warning during compilation [-Wstringop-overflow=]
that the size exceeds maximum object size 9223372036854775807

#include <stdio.h>
#include <string.h>
void		*ft_memcpy(void *to, const void *from, size_t n);

int main(void) {

	char* str;
	char* ptr;

	int c1;
	int* p1;
	int c2;
	int* p2;
	int c3;
	int* p3;

	c1 = 'A';
	p1 = &c1;
	c2 = 'Z';
	p2 = &c2;
	c3 = 'X';
	p3 = &c3;

	if(c1 == c2)
		printf("Not correct");

	ft_bzero(p1,1);
	bzero(p2,1);

	if(c1 == c2)
		printf("correct\n");
	if(c1 == c3)
		printf("c1 is equal to c3 : Not correct\n");

	ft_memcpy(p3,p1,1);
	if(c1 == c3)
		printf("c1 == c3 : Correct\n");
	//this last one is weird
	if(c1 == c2)
		printf("c1 is equal to c2 : Not correct\n");
}
*/
