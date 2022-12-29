/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjirapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 11:54:30 by yjirapin          #+#    #+#             */
/*   Updated: 2022/03/04 14:35:02 by yjirapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/* ft_memset() is used to fill a block of memory with a particular value.
The syntax of ft_memset() function is as follows :

 ptr ==> Starting address of memory to be filled
 x   ==> Value to be filled
 n   ==> Number of bytes to be filled starting
         from ptr to be filled
Note that ptr is a void pointer, so that we can
 any type of pointer to this function.
	Ex:char str[50] = "Fear is the mind-killer.";
       Now Fill 8 characters starting from str[13] with '.'
       ft_memset(str + 11, '.', 6*sizeof(char));
	   str is now "Fear is the......killer."
*/

void	*ft_memset(void *pointme, int coolbean, size_t sandworm)
{
	size_t				i;
	unsigned char		*ptr;

	i = 0;
	ptr = (unsigned char *)pointme;
	while (i < sandworm)
		ptr[i++] = (unsigned char)coolbean;
	return (pointme);
}
