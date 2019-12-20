/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specification.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-kad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 16:58:04 by yait-kad          #+#    #+#             */
/*   Updated: 2019/12/15 02:00:21 by yait-kad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>

t_str       *check_flags(t_str *tab)
{
  while (tab->format[tab->i] == '0' || tab->format[tab->i] == '-')
  {
    if (tab->format[tab->i] == '-')
      tab->flags[0] = '-';
    else if (tab->format[tab->i] == '0')
      tab->flags[1] = '0';
    tab->i++;
  }
  return (tab);
}

t_str     *check_width(t_str *tab)
{
	int i;
	if (tab->format[tab->i] == '*')
	{
		tab->i++;
		i = va_arg(tab->ap, int);
		if (i < 0)
		{
			tab->flags[0] = '-';
			i = i*(-1);
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

t_str     *check_precision(t_str *tab)
{
	int	i;
	while (tab->format[tab->i] == '.')
	{
		tab->i++;
		if (tab->format[tab->i] == '*')
		{
			tab->i++;
			i = va_arg(tab->ap, int);
			if (i < 0)
				tab->precision = 0;
			else
				tab->precision = i;
			
		}else if (tab->format[tab->i] > '0' && tab->format[tab->i] <= '9')
		{
			while (tab->format[tab->i] >= '0' && tab->format[tab->i] <= '9')
			{
				tab->precision *= 10;
				tab->precision += (tab->format[tab->i] - 48);
				tab->i++;
			}
		}else
		{
			tab->precision = -1;
			if (tab->format[tab->i] == '0')
			{
				tab->precision = 0;
				tab->i++;
			}
		}
	}
	return (tab);
}

t_str     *specification(t_str *tab)
{
	tab = check_flags(tab);
	tab = check_width(tab);
	tab = check_precision(tab);
	if (tab->format[tab->i] == 'c')
    	char_c(tab);
	else if (tab->format[tab->i] == 's')
    	string_s(tab);
	else if (tab->format[tab->i] == 'd' || tab->format[tab->i] == 'i')
		decimal_d(tab);
	/*else if (tab->format[tab->i] == 'u')
    	unsigned_u(tab);
	else if (tab->format[tab->i] == 'x' || tab->format[tab->i] == 'X')
    	hex_x(tab);
	else if (tab->format[tab->i] == 'p')
    	pointer_p(tab);
	else if (tab->format[tab->i] == '%')
    	percent(tab);
	else
		tab->i++;*/
	return (tab);
}
