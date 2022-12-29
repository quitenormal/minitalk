/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjirapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 20:17:33 by yjirapin          #+#    #+#             */
/*   Updated: 2022/03/11 22:11:00 by yjirapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

// ft_strrchr function searches within the string pointed to by
// str for the character c. It returns the pointer to the string
// or rather the substring that starts with C.

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	char	*s;

	s = (char *)str;
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (unsigned char)c)
			return (&s[i]);
		i--;
	}
	return (0);
}

/* A bedtime story (Dev's notes)

Once upon a time, there was a function named ft_strrchr
It takes a string and a character. We'll call this character, THE ONE.

char	*ft_strrchr(const char *str, int c)
{

	int		i;
	char	*s;

Internally, it will put the string into an internal string called s.
The s gets casted as a char because str is const char.

	s = (char *)str;
	i = ft_strlen(s);

An internal integer called i is intially the &s[i]is returned.
If it reaches the beginning of the string and still not match,
then 0 is returned.
Note: I removed the (char *) from return ((char *)&s[i]) because
s is not a const.

	while (i >= 0)
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i--;
	}
	return (0);
}

*/
