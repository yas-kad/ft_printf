/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-kad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 23:37:35 by yait-kad          #+#    #+#             */
/*   Updated: 2019/12/29 23:37:37 by yait-kad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_str		*check_width(t_str *tab)
{
	int i;

	if (tab->format[tab->i] == '*')
	{
		tab->i++;
		i = va_arg(tab->ap, int);
		if (i < 0)
		{
			tab->flags[0] = '-';
			i = i * (-1);
		}
		tab->width = i;
	}
	else
	{
		while (tab->format[tab->i] >= '0' && tab->format[tab->i] <= '9')
		{
			tab->width *= 10;
			tab->width += (tab->format[tab->i] - 48);
			tab->i++;
		}
	}
	return (tab);
}
