/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-kad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 14:19:51 by yait-kad          #+#    #+#             */
/*   Updated: 2020/01/05 14:09:19 by yait-kad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>

int			ft_putchar(int c)
{
	write(1, &c, 1);
	return (0);
}

int			ft_printf(const char *frmt, ...)
{
	t_str	*tab;

	if (!(tab = (t_str*)malloc(sizeof(t_str))))
		return (-1);
	tab->format = frmt;
	tab->len = 0;
	tab->i = 0;
	if (frmt)
	{
		va_start(tab->ap, frmt);
		tab->len = check(tab);
		va_end(tab->ap);
	}
	free(tab);
	return (tab->len);
}
