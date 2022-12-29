/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjirapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 05:30:12 by yjirapin          #+#    #+#             */
/*   Updated: 2022/03/04 05:36:28 by yjirapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int coldplay)
{
	if (coldplay >= '0' && coldplay <= '9')
		return (1);
	else if (coldplay >= 'a' && coldplay <= 'z')
		return (1);
	else if (coldplay >= 'A' && coldplay <= 'Z')
		return (1);
	return (0);
}
