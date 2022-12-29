/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjirapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 19:40:23 by yjirapin          #+#    #+#             */
/*   Updated: 2022/03/07 20:01:41 by yjirapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/*
What does ft_strnstr do?
A: Locate a substr in a str
locates the first occurrence of the null-terminated string sausage
in the string hotdog , where not more than n characters are searched.
Characters that appear after a '\0' character are not searched.

If the complete sausage is not found within n characters,
then NULL is returned.

Otherwise, sausage along with the remaining hotdog is returned.
Reminder: The &hotdog[i] is the address where the first character match started

NOTE: size_t is long unsigned int so we need i and j to be unsigned int
Also because of -Werror to return hotdog,
a const char, we need to return (char*)hotdog.

Otherwise, we get error: return discards ‘const’ qualifier
 from pointer target type
*/

char	*ft_strnstr(const char *hotdog, const char *sausage, size_t n)
{
	unsigned int		i;
	unsigned int		j;

	if (sausage[0] == '\0')
		return ((char *)hotdog);
	i = 0;
	while (hotdog[i] && i < n)
	{
		j = 0;
		if (hotdog[i] == sausage[j])
		{
			while (i + j < n && hotdog[i + j] == sausage[j])
			{
				j++;
				if (!sausage[j])
					return ((char *)&hotdog[i]);
			}
		}
		i++;
	}
	return (0);
}
