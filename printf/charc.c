/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-kad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 15:31:33 by yait-kad          #+#    #+#             */
/*   Updated: 2019/12/29 19:30:39 by yait-kad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdlib.h>

void		affichage(t_str *tab, char *result, char print, int i)
{
	if (tab->flags[0] == '-')
	{
		if (tab->format[tab->i] == 'c' && print == 0)
		{
			write(1, "\0", 1);
			ft_putstr(&*result + 1);
		}
		else
			ft_putstr(result);
	}
	else
	{
		result = reverse(result, i);
		ft_putstr(result);
		if (tab->format[tab->i] == 'c' && print == 0)
		{
			write(1, "\0", 1);
		}
	}
	free(result);
}

void		charc(t_str *tab, char print)
{
	char		*result;
	int			i;

	i = 0;
	result = (char *)malloc(tab->width + 1);
	result[0] = print;
	result[1] = '\0';
	i++;
	if (tab->width)
		while (i < tab->width)
			result[i++] = ' ';
	if (tab->width > 0 && tab->tst_prec == '.' && tab->flags[0] != '-'
												&& tab->flags[1] == '0')
	{
		i = 1;
		while (i < tab->width)
			result[i++] = '0';
	}
	result[i] = '\0';
	tab->len = tab->len + i;
	affichage(tab, result, print, i);
}
