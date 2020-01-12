/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-kad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 05:04:08 by yait-kad          #+#    #+#             */
/*   Updated: 2019/12/28 11:10:08 by yait-kad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_lenth(unsigned int nb)
{
	int i;

	i = 1;
	while (nb > 9)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

char	*ft_uitoa(unsigned int n)
{
	char	*dest;
	int		len;
	int		i;

	i = 0;
	len = ft_lenth(n);
	if (!(dest = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	len--;
	while (i <= len)
	{
		dest[len] = ((n % 10) + 48);
		n = n / 10;
		len--;
	}
	return (dest);
}
