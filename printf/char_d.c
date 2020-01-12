/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-kad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 15:03:11 by yait-kad          #+#    #+#             */
/*   Updated: 2020/01/08 14:55:50 by yait-kad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdlib.h>

char		*flags_d(t_str *tab, int i, char *result)
{
	char	*ptr;
	int		size;

	size = tab->width - i;
	i = 0;
	ptr = (char *)malloc(size + 1);
	while (i < size)
	{
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

int			len_num(t_str *tab, int nbr_len1)
{
	if ((tab->flags[1] != '0') || (tab->flags[1] == '0' &&
									tab->width > 0 && tab->prec_neg != -1))
		nbr_len1 = nbr_len1 - 2;
	else if (tab->precision >= nbr_len1 && tab->tst_prec == '.' &&
											tab->prec_neg != -1)
		nbr_len1 = nbr_len1 - 2;
	else
		nbr_len1 = nbr_len1 - 1;
	return (nbr_len1);
}

char		*str_join(char *result, char *nbr_str, int i)
{
	int		j;

	j = 0;
	while ((nbr_str[j] != '\0'))
		result[i++] = nbr_str[j++];
	result[i] = '\0';
	return (result);
}

char		*char_d(t_str *tab, int nbr_len, char *nbr_str)
{
	char	*result;
	char	*tmp;
	int		i;

	i = 0;
	result = (char *)malloc(10000);
	if (tab->value_d < 0)
	{
		result[i++] = '-';
		nbr_len = len_num(tab, nbr_len);
	}
	if (tab->precision > nbr_len && tab->prec_neg != -1)
		while (i < (tab->precision - nbr_len))
			result[i++] = '0';
	result[i] = '\0';
	result = str_join(result, nbr_str, i);
	i = ft_strlen(result);
	if (tab->width_1 == 1 || (tab->width > nbr_len &&
							tab->width >= tab->precision))
	{
		tmp = result;
		result = flags_d(tab, i, result);
		free(tmp);
	}
	return (result);
}
