/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-kad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 23:58:51 by yait-kad          #+#    #+#             */
/*   Updated: 2019/12/28 10:28:01 by yait-kad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdlib.h>

void		ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

char		*reverse(char *str2, int i)
{
	char	*ch;
	int		j;

	ch = malloc(i);
	j = 0;
	i--;
	while (i >= 0)
	{
		ch[j] = str2[i];
		i--;
		j++;
	}
	ch[j] = '\0';
	return (ch);
}

void		charc(t_str *tab, char print)
{
	char		*result;
	int			i;

	i = 0;
	result = malloc(2);
	result[0] = print;
	result[1] = '\0';
	i++;
	if (tab->width)
	{
		while (i < tab->width)
		{
			result[i] = ' ';
			i++;
		}
	}
	result[i] = '\0';
	tab->len = i;
	if (tab->flags[0] == '-')
	{
		free(result);
		ft_putstr(result);
	}
	else
	{
		result = reverse(result, i);
		free(result);
		ft_putstr(result);
	}
}

void		char_c(t_str *tab)
{
	char print;

	print = va_arg(tab->ap, int);
	charc(tab, print);
}
