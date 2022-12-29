/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjirapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 14:27:02 by yjirapin          #+#    #+#             */
/*   Updated: 2022/03/13 18:33:32 by yjirapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* The function ft_strmapi takes a string and a pointer to
a destination function. The output of the destination function
is a character. The function ft_strmapi returns a string.
*/

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char	*fx;
	size_t	len;
	int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	len = ft_strlen((char *)s);
	fx = malloc((len + 1) * sizeof(char));
	if (fx == NULL)
		return (NULL);
	fx[len] = '\0';
	while (s[i] != '\0')
	{
		fx[i] = (*f)(i, s[i]);
		i++;
	}
	return (fx);
}

/* Dev's note
This is just like ft_striteri except that
the destination function returns a string.
*/
