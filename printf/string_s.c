/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-kad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 06:32:32 by yait-kad          #+#    #+#             */
/*   Updated: 2019/12/16 06:32:38 by yait-kad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>


char		*check_string(t_str *tab, char *str, int compt, int width)
{
	char	*result;
    char    *ptr;
	int		i;
	int		size;

    i = 0;
    size = compt;
    result = malloc(compt + 1);
    if (compt > 0)
    {
	    while (str[i] != '\0' && compt > 0)
        {
            result[i] = str[i];
            compt--;
            i++;
        }
        result[i] = '\0';
    }
    if (width > size)
    {
        size = width - size;
        i = 0;
        ptr = malloc(size + 1);
        while (i < size)
        {
            ptr[i++] = ' ';
        }
        ptr[i] = '\0';
        if (tab->flags[0] == '-')
            result = ft_strjoin(result,ptr);
        else
            result = ft_strjoin(ptr,result);
    }
	return (result);
}

void    string_s(t_str *tab)
{
    char    *str;
    char    *result;
    int     len;

    str   = va_arg(tab->ap,char *);
    if (tab->precision > 0)
    {
        result = check_string(tab, str, tab->precision, tab->width);
    }
    else if (tab->precision < 0)
        result = check_string(tab, str, 0, tab->width);
    else
    {
        len = ft_strlen(str);
        result = check_string(tab, str, len, tab->width);
    }
    tab->len = tab->len + ft_strlen(result);
    ft_putstr(result);
}
