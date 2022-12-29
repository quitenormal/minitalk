/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjirapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 14:17:18 by yjirapin          #+#    #+#             */
/*   Updated: 2022/03/16 13:18:32 by yjirapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

static unsigned int	in_this_set(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int				i;
	unsigned int	outstr_size;
	char			*start;
	char			*end;
	char			*outstr;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	while (s1[i] && in_this_set(s1[i], set))
		i++;
	start = (char *)&s1[i];
	i = ft_strlen((char *)(s1)) - 1;
	while (i >= 0 && in_this_set(s1[i], set))
		i--;
	end = (char *)&s1[i];
	outstr_size = end - start + 2;
	if (!*s1 || end == start)
		outstr_size = 2;
	outstr = malloc(sizeof(char) * outstr_size);
	if (!outstr)
		return (NULL);
	ft_strlcpy(outstr, start, outstr_size);
	return (outstr);
}

/* main function for testing
*/

/* Bedtime story: Dev's notes

If s1 or set is NULL then end it.
	if (!s1 || !set)
		return (NULL);
For the original string, check each character:
While s1[i] is not NULL and matches the set,
move down one character.
	i = 0;
	while (s1[i] && is_this(s1[i], set))
		i++;
Once there is no match, this marks
 the start of the trimmed string.
Start is the pointer for this starting point (&s1[i])
It was casted as char because s1 is a const.
	start = (char *)&s1[i];
Now we'll reuse i to be the end of the string.
ft_strlen gives us that number (which we substract by 1
in order to ignore the \0 at the end).
	i = ft_strlen((char *)(s1)) - 1;
The i is decreased by 1 as we move from the back of the string
to find a character that does not belong to the set.
	while (i >= 0 && is_this(s1[i], set))
		i--;
End is the pointer for this end point (&s1[i])
	end = (char *)&s1[i];
Thus the size of the output str will be end - start + 2.
We add 2 (1 for the \0 and 1 for the len)
	outstr_size = end - start + 2;
If end = start, then the size will only be 2 for the first
character and the \0 character.
	if (!*s1 || end == start)
		outstr_size = 2;
Now we know the size, we can allocate memory for that size.
	outstr = malloc(sizeof(char) * outstr_size);
	if (!outstr)
		return (NULL);
The outstr is created from the start with a length of
outstr_size.
	ft_strlcpy(outstr, start, outstr_size);
	return (outstr);

It's really cool how we can use a pointer to signify
 a string like this. I am getting the hang of it now.
 The & sign is a powerful one. Must learn to use more
 often.
}
*/
