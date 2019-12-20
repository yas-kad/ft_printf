/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-kad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 17:48:59 by yait-kad          #+#    #+#             */
/*   Updated: 2019/12/08 18:03:21 by yait-kad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

t_str		*display(t_str *tab)
{
	char flag;
	unsigned int c;
	char		*ch;

	flag = tab->specifier_flag;
	if (flag == 'd' || flag == 'i')
	{
		c = va_arg(tab->ap,int);
		write(1, &c, 1);
	}
	else if (flag == 'c')
	{
		c = va_arg(tab->ap,int);
		write(1, &c, 1);
	}
	else if (flag == 's')
	{
		ch = va_arg(tab->ap,char *);
		puts(ch);
	}
	else if (flag == 'p')
	{
		c = va_arg(tab->ap,int);
	}
	else if (flag == 'u')
	{
		c = va_arg(tab->ap,int);
	}
	else if (flag == 'x' || flag == 'X')
	{
		c = va_arg(tab->ap,int);
	}
	return (tab);
}