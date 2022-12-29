/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjirapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 06:54:43 by yjirapin          #+#    #+#             */
/*   Updated: 2022/03/04 15:10:58 by yjirapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

isspace 9 - 13 and 32

while (str[i] && (str[i] == '\f' || str[i] == '\t' || str[i] == ' ' ||
			str[i] == '\n' || str[i] == '\r' || str[i] == '\v'))

** While the current char in the string is a whitespace ..
**  increase str until it isn't a space.
** Set the starting result to zero.
** Set the sign to -1 if we have a '-'
** Increase past the sign char.
** For this next loop, use an i
** While we are not at the \0 and we have a digit char
**  take the result and set it to:
**   The result * 10 + the current digitchar minus the '0' char.
** Return the result time the sign.
*/

int	ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || (c == 32))
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	result;
	int	i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i++] - '0';
	}
	result *= sign;
	return (result);
}
