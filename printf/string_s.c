/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-kad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 06:32:32 by yait-kad          #+#    #+#             */
/*   Updated: 2019/12/28 13:03:17 by yait-kad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

char		*resultat(t_str *tab, int size, char *result)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = (char *)malloc(size + 1);
	if (tab->flags[0] != '-' && tab->flags[1] == '0')
	{
		while (i < size)
			ptr[i++] = '0';
	}
	else
	{
		while (i < size)
			ptr[i++] = ' ';
	}
	ptr[i] = '\0';
	if (tab->flags[0] == '-')
		result = ft_strjoin(result, ptr);
	else
		result = ft_strjoin(ptr, result);
	free(ptr);
	return (result);
}

char		*check_string(t_str *tab, char *str, int compt, int width)
{
	char	*result;
	char	*tmp;
	int		i;
	int		size;

	i = 0;
	size = compt;
	result = (char *)malloc(compt + 1);
	if (compt > 0)
	{
		while (str[i] != '\0' && compt-- > 0)
		{
			result[i] = str[i];
			i++;
		}
		result[i] = '\0';
	}
	if (width > size)
	{
		tmp = result;
		size = width - size;
		result = resultat(tab, size, result);
		free(tmp);
	}
	return (result);
}

char		*check_prec(t_str *tab, char *str, int len)
{
	char	*result;

	if (tab->precision >= tab->width && tab->width > 0)
	{
		if (tab->precision < len)
			result = check_string(tab, str, tab->precision, tab->width);
		else
			result = check_string(tab, str, len, tab->width);
	}
	else
	{
		if (tab->precision > len)
			result = check_string(tab, str, len, tab->width);
		else
			result = check_string(tab, str, tab->precision, tab->width);
	}
	return (result);
}

void		string_s(t_str *tab)
{
	char	*result;
	char	*str;
	int		len;

	str = va_arg(tab->ap, char *);
	if (str == NULL)
		str = "(null)";
	len = ft_strlen(str);
	if (tab->precision >= 0)
	{
		if (tab->precision > 0)
			result = check_prec(tab, str, len);
		else if (tab->width >= tab->precision && tab->precision > 0)
			result = check_string(tab, str, len, tab->width);
		else
			result = check_string(tab, str, 0, tab->width);
	}
	else
		result = check_string(tab, str, len, tab->width);
	tab->len = tab->len + ft_strlen(result);
	ft_putstr(result);
	free(result);
}
