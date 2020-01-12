/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-kad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 07:58:07 by yait-kad          #+#    #+#             */
/*   Updated: 2019/12/28 11:21:52 by yait-kad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdlib.h>

void		percent(t_str *tab)
{
	char	*result;

	if (tab->tst_prec != '.' && tab->flags[1] == '0' && tab->flags[0] != '-')
	{
		tab->precision = tab->width;
		tab->width = 0;
		result = char_d(tab, 1, "%");
		tab->len = tab->len + ft_strlen(result);
		ft_putstr(result);
		free(result);
	}
	else
		charc(tab, tab->format[tab->i]);
}
