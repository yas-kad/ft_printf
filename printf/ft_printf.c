/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-kad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 14:19:51 by yait-kad          #+#    #+#             */
/*   Updated: 2019/12/15 02:43:40 by yait-kad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include "libft/libft.h"


int			ft_putchar(int c)
{
	write(1, &c, 1);
	return (0);
}

int		check(t_str *tab)
{
	if (strcmp(tab->format, "%") == 0)
		return (-1);
	while (tab->format[tab->i] != '\0')
	{
		if (tab->format[tab->i] == '%')
		{
			tab->i++;
			tab->width = 0;
			tab->precision = 0;
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

int		ft_printf(const char *frmt, ...)
{
	t_str	*tab;

	if (!(tab = (t_str*)malloc(sizeof(t_str))))
		return (-1);
	tab->format = frmt;
	tab->len = 0;
	tab->i = 0;
	if (frmt)
	{
		va_start(tab->ap,frmt);
		tab->len = check(tab);
		va_end(tab->ap);
	}
	return (tab->len);
}
int		main()
{
	int d = ft_printf("|%4.5i|",2);
	//printf("%d",d);
	return 0;
}

