/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjirapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 12:21:11 by yjirapin          #+#    #+#             */
/*   Updated: 2022/03/08 16:46:57 by yjirapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ft_split is used to break a delimited string into substrings.
You can use either a character array or a string array to specify zero or more
 delimiting characters or strings. If no delimiting characters are specified,
 the string is split at white-space characters.
 */

/* We have a rather private function here called count_dracula which
takes a string and a character and returns an integer that represents
the number of times the character is found in the string. It's
magnificent.
*/

static int	count_dracula(const char *str, char c)
{
	int	i;
	int	trigger;

	i = 0;
	trigger = 0;
	while (*str)
	{
		if (*str != c && trigger == 0)
		{
			trigger = 1;
			i++;
		}
		else if (*str == c)
			trigger = 0;
		str++;
	}
	return (i);
}

/* Here is a very private function that likes to read and enjoys
time alone. Most people call her "wordle". She will take a string and
two integers then send you a string. What she is really doing is she
is returning an excerpt between two points (start and finish)
in the original string.
*/

static char	*wordle(const char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((finish - start + 1) * sizeof(char));
	while (start < finish)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

/* How do you like that Norminette?
ft_split returns a pointer to a string (or an array of string)
because it can.

i keeps track of characters in the entire string starting from zero.
j keeps track of individual words in the split (array of string)
			split[j++] = wordle(str, x, i);
x starts with -1 but gets changed to i if the first character is not c.
x is changed to -1 again when it finds a c and an excert is taken.
*/

char	**ft_split(char const *str, char c)
{
	size_t	i;
	size_t	j;
	int		x;
	char	**split;

	split = malloc((count_dracula(str, c) + 1) * sizeof(char *));
	if (!str || !(split))
		return (0);
	i = 0;
	j = 0;
	x = -1;
	while (i <= (size_t)ft_strlen((char *)str))
	{
		if (str[i] != c && x < 0)
			x = i;
		else if ((str[i] == c || i == (size_t)ft_strlen((char *)str)) && x >= 0)
		{
			split[j++] = wordle(str, x, i);
			x = -1;
		}
		i++;
	}
	split[j] = 0;
	return (split);
}
