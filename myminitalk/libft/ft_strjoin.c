/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjirapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:23:16 by yjirapin          #+#    #+#             */
/*   Updated: 2022/03/08 06:55:49 by yjirapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char const *str);

// ft_strlen takes two strings src and dest and put them together as
// dest+src and put into desc

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		len1;
	int		len2;
	int		i;
	int		j;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	i = 0;
	while (i < len1)
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < len2)
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

/* Main function

#include <stdio.h>

int main (){
    char *answer;

    answer = ft_strjoin("mama","");
    printf("The answer is %s \n",answer);
    free(answer);
    answer = ft_strjoin("","");
    printf("The answer is %s \n",answer);
    free(answer);
    answer = ft_strjoin("","mama");
    printf("The answer is %s \n",answer);
    free(answer);
    answer = ft_strjoin("mama","papa");
    printf("The answer is %s \n",answer);
    free(answer);
    return(0);
}
*/
