/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-kad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 15:32:44 by yait-kad          #+#    #+#             */
/*   Updated: 2019/12/29 15:32:46 by yait-kad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdlib.h>

char		*reverse(char *str2, int i)
{
	char	*ch;
	int		j;

	ch = (char *)malloc(i);
	j = 0;
	i--;
	while (i >= 0)
	{
		ch[j] = str2[i];
		i--;
		j++;
	}
	ch[j] = '\0';
	free(str2);
	return (ch);
}
