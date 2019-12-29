/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-kad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 17:48:59 by yait-kad          #+#    #+#             */
/*   Updated: 2019/12/28 10:22:17 by yait-kad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int		check(t_str *tab)
{
	if (ft_strcmp(tab->format, "%") == 0)
		return (-1);
	while (tab->format[tab->i] != '\0')
	{
		if (tab->format[tab->i] == '%')
		{
			tab->i++;
			tab->width = 0;
			tab->precision = -1;
			tab->flags = malloc(2);
			tab->flags[0] = '\0';
			tab->flags[1] = '\0';
			specification(tab);
		}
		else
		{
			ft_putchar(tab->format[tab->i]);
			tab->len++;
		}
		tab->i++;
	}
	return (tab->len);
}
