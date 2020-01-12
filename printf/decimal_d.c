/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-kad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 18:13:50 by yait-kad          #+#    #+#             */
/*   Updated: 2020/01/08 14:54:23 by yait-kad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdlib.h>

t_str		*cas_special(t_str *tab)
{
	tab->precision = tab->width;
	tab->width = 0;
	return (tab);
}

void		decimal_d(t_str *tab)
{
	t_dcml a;

	if (tab->tst_prec != '.' && tab->flags[1] == '0')
		tab = cas_special(tab);
	a.nbr = va_arg(tab->ap, int);
	a.nbr_str = ft_itoa(a.nbr);
	a.nbr_len = ft_strlen(a.nbr_str);
	if (a.nbr < 0)
	{
		a.tmp = a.nbr_str;
		a.nbr_str = ft_strdup(&*a.nbr_str + 1);
		tab->value_d = a.nbr;
		free(a.tmp);
	}
	if (tab->precision == 0 && a.nbr == 0)
		a.nbr_str[0] = '\0';
	if (tab->width == 1 && a.nbr == 0 && tab->precision == 0)
		tab->width_1 = 1;
	a.result = char_d(tab, a.nbr_len, a.nbr_str);
	tab->len = tab->len + ft_strlen(a.result);
	ft_putstr(a.result);
	free(a.nbr_str);
	free(a.result);
	a.nbr_len = 0;
	a.nbr = 0;
}
