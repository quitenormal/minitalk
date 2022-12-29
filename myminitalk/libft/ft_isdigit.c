/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjirapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 21:55:39 by yjirapin          #+#    #+#             */
/*   Updated: 2022/03/03 22:52:07 by yjirapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//“Two possibilities exist: either we are alone in the Universe or
// we are not. Both are equally terrifying.” ― Arthur C. Clarke

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}
