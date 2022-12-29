/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjirapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 07:08:11 by yjirapin          #+#    #+#             */
/*   Updated: 2022/03/16 14:40:21 by yjirapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// s: The string from which to create the substring.
// start: The start index of the substring in the
// string ’s’.
// len: The maximum length of the substring.

// Thisstr doesn't change so we do not need malloc

	//allocate memory of (len + 1) chars for substring
	//(+1 for extra null character)
	//char *str = malloc(sizeof(char) * (len + 1));
	//handle empty string with if(!str) return (NULL)
	//str[j] = 0 last character of a string is 0

/*ft_mystronebyte
is for returning a str with just \0 and a size of one byte.
You only need this when start >= s_len where s_len = ft_strlen(s)
which means that the starting point is even longer than the entire
string. I guess that's how substr.c does it.
The header file "string.h" does not contain any library function
 to find a substring directly.

For other cases, this is how you should do it.
Normally, the memory needed is just the length of the substring.
str = (char *) malloc(sizeof(char) * (len + 1))
But if the entire string size is less or equal to the length
of the substring (s_len <= len) then use the entire string size
minus the starting point instead.
		str = (char *) malloc(sizeof(char) * (s_len - start + 1));
*/

static char	*ft_mystronebyte(void)
{
	char	*str;

	str = (char *) malloc(sizeof(char));
	if (!str)
		return (NULL);
	str[0] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	s_len;

	s_len = ft_strlen(s);
	if (start >= s_len)
	{
		str = ft_mystronebyte();
		return (str);
	}
	if (s_len <= len)
		str = (char *) malloc(sizeof(char) * (s_len - start + 1));
	else
		str = (char *) malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < len && s[i + start] != '\0')
	{
		str[i] = s[i + start];
		i++;
	}
	str[i] = '\0';
	return (str);
}

/* Main function to test

#include <stdio.h>

int	main(void)
{
	char	*thisstr;
	char	*thatsub;

	thisstr = "supertestimonial";
	thatsub = ft_substr(thisstr, 5, 4);
	printf("The answer is %s \n", thatsub);
	free(thatsub);
	thisstr = "There will be a day that we will die";
	thatsub = ft_substr(thisstr, 30, 7);
	printf("The answer is %s \n", thatsub);
	free(thatsub);
	thisstr = "";
	thatsub = ft_substr(thisstr, 7, 3);
	printf("The answer is %s \n", thatsub);
	free(thatsub);
	return (0);
}
*/
