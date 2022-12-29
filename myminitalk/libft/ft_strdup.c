/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjirapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 00:23:06 by yjirapin          #+#    #+#             */
/*   Updated: 2022/03/08 00:46:28 by yjirapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

/******************************
ft_strdup is used to duplicate a string.
It returns a pointer to null-terminated byte string.
*/

int	ft_strlen(char *str);

char	*ft_strdup(const char *string)
{
	int		i;
	int		len;
	char	*ptr;

	i = 0;
	len = ft_strlen((char *)string);
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);
	while (i < len)
	{
		ptr[i] = string[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

/* Main function to test

#include <stdio.h>
#include <string.h>

int main() {
   char *str = "Helloworld\n";
   char *result1;
   char *result2;

	result1 = strdup(str);
	result2 = ft_strdup(str);
	printf("strdup : %s", result1);
	printf("ft_strdup : %s", result2);
	free(result1);
	free(result2);
	return 0;
}

*/
