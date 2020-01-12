/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-kad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 23:34:39 by yait-kad          #+#    #+#             */
/*   Updated: 2019/12/29 23:34:41 by yait-kad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_str		*check_flags(t_str *tab)
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
