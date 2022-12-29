/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjirapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 23:04:52 by yjirapin          #+#    #+#             */
/*   Updated: 2022/03/08 00:21:52 by yjirapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

/* ft_calloc allocates a specified amount of memory and initializes it to zero.
The function returns a void pointer to this memory location,
which can then be cast to the desired type.
The function takes in two parameters that collectively specify
 the amount of memory ​​to be allocated.
*/

void	*ft_calloc(size_t count, size_t size)
{
	char			*dst;
	unsigned int	total;
	unsigned int	i;

	total = count * size;
	dst = (char *)malloc(total);
	if (!dst)
		return (NULL);
	i = 0;
	while (total--)
	{
		dst[i] = 0;
		i++;
	}
	return ((void *)dst);
}

/* Main function for testing
#include <stdio.h>

int main(void){

	int* a = (int*) calloc(5, sizeof(int));
	if(!a)
		return(1);
	int* b = (int*) ft_calloc(5, sizeof(int));
	if(!b)
		return(1);

	printf("Calloc: %p and %d %d %d %d\n",a,*a, *(a+2),*(a+5),*(a+6));
	printf("ft_calloc: %p and %d %d %d %d\n",b,*b,*(b+2),*(b+5),*(b+6));
	free(a);
	free(b);
	return(0);
}
*/
