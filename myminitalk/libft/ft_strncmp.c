/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjirapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 20:32:45 by yjirapin          #+#    #+#             */
/*   Updated: 2022/03/07 22:52:48 by yjirapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/* ft_strncmp compares at most the first n bytes of str1 and str2.
if Return value < 0 then it indicates str1 is less than str2.
if Return value > 0 then it indicates str2 is less than str1.
if Return value = 0 then it indicates str1 is equal to str2.
*/

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0' && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/********
Main function to test ft_strncmp

#include <stdio.h>
#include <string.h>

int	main(void){

	char *mytest;
	char *yourtest;

	mytest = "test\200";
	yourtest = "test\0";

	printf("strncmp: %d\n",strncmp(mytest,yourtest,6));
	printf("ft_strncmp: %d\n",ft_strncmp(mytest,yourtest,6));

	return(0);
}
*/
