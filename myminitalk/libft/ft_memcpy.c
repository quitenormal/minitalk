/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjirapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 12:31:42 by yjirapin          #+#    #+#             */
/*   Updated: 2022/03/04 14:00:00 by yjirapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/*********
The function ft_memcpy() is used to copy a memory block
from one location to another.
One is source and another is destination pointed by the pointer.
It does not check for overflow.
Syntax of ft_memcpy()
	void *ft_memcpy(void *dest_str, const void *src_str, size_t number)
	dest_str − Pointer to the destination array.
	src_str − Pointer to the source array.
	number − The number of bytes to be copied from source to destination.
   Ex: char a[] = "A poison needle";
   const char b[] = "The Gom Jabbar is instant death.";
   memcpy(a, b, 14);
   a is now "The Gom Jabbar "
*/

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dst_ptr;
	unsigned char		*src_ptr;

	if (!src && !dst)
		return (NULL);
	dst_ptr = (unsigned char *)dst;
	src_ptr = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dst_ptr[i] = src_ptr[i];
		i++;
	}
	return (dst_ptr);
}
