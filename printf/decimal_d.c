/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-kad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 18:13:50 by yait-kad          #+#    #+#             */
/*   Updated: 2019/12/16 18:13:53 by yait-kad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>



void        decimal_d(t_str *tab)
{
    char    *nbr_str;
    char    *result;
	int		nbr;
	int		nbr_len;
	int		size;
	char	*ptr;
	int		i;
	int		j;

    i = 0;
	j = 0;
    nbr = va_arg(tab->ap, int);
	nbr_str = ft_itoa(nbr);
	//printf("%s\n",nbr_str);
	nbr_len = ft_strlen(nbr_str);
	result = malloc(nbr_len);
	if (tab->precision == 0 && nbr == 0)
		nbr_str[j] = '\0';
	if (tab->precision > nbr_len)
	{
		while (i < (tab->precision - nbr_len))
		{
			result[i] = '0';
			i++;
		}
	}
	while ((nbr_str[j] != '\0'))
	{
		result[i] = nbr_str[j];
		i++;
		j++;
	}
	result[i] = '\0';
	if (tab->width > nbr_len && tab->width > tab->precision)
	{
		size = tab->width - i;
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
	tab->len = tab->len + ft_strlen(result);
    ft_putstr(result);
}