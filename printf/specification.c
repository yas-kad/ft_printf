/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specification.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-kad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 16:58:04 by yait-kad          #+#    #+#             */
/*   Updated: 2019/12/28 11:39:25 by yait-kad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_str		*nbr_put(t_str *tab)
{
	while (tab->format[tab->i] >= '0' && tab->format[tab->i] <= '9')
	{
		tab->precision *= 10;
		tab->precision += (tab->format[tab->i] - 48);
		tab->i++;
	}
	return (tab);
}

t_str		*etoile(t_str *tab)
{
	int	i;

	i = va_arg(tab->ap, int);
	if (i < 0)
	{
		if (tab->flags[1] == '0')
		{
			tab->precision = tab->width;
			tab->prec_neg = -1;
		}
		else
			tab->precision = -1;
	}
	else
		tab->precision = i;
	return (tab);
}

t_str		*check_precision(t_str *tab)
{
	tab->tst_prec = tab->format[tab->i];
	while (tab->format[tab->i] == '.')
	{
		tab->i++;
		if (tab->format[tab->i] == '*')
		{
			tab->i++;
			tab = etoile(tab);
		}
		else if (tab->format[tab->i] >= '0' && tab->format[tab->i] <= '9')
		{
			tab->precision = 0;
			tab = nbr_put(tab);
		}
		else
			tab->precision = 0;
	}
	return (tab);
}

t_str		*specification(t_str *tab)
{
	tab->width_1 = 0;
	tab = check_flags(tab);
	tab = check_width(tab);
	tab = check_precision(tab);
	if (tab->format[tab->i] == 'c')
		char_c(tab);
	else if (tab->format[tab->i] == 's')
		string_s(tab);
	else if (tab->format[tab->i] == 'd' || tab->format[tab->i] == 'i')
		decimal_d(tab);
	else if (tab->format[tab->i] == 'u')
		unsigned_u(tab);
	else if (tab->format[tab->i] == 'x' || tab->format[tab->i] == 'X')
		hex_x(tab, tab->format[tab->i]);
	else if (tab->format[tab->i] == 'p')
		pointer_p(tab);
	else if (tab->format[tab->i] == '%')
		percent(tab);
	else
		tab->i--;
	free(tab->flags);
	return (tab);
}
