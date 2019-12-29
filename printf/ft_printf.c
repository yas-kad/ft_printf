/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-kad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 14:19:51 by yait-kad          #+#    #+#             */
/*   Updated: 2019/12/28 10:20:17 by yait-kad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>
#include "libft/libft.h"
#include <stdio.h>

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
	free(tab->flags);
	free(tab);
	return (tab->len);
}
int main()
{
	ft_printf("|%.3x|\n",938862);
	printf("|%.3x|\n",938862);
}