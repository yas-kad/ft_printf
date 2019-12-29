/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-kad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 15:03:11 by yait-kad          #+#    #+#             */
/*   Updated: 2019/12/29 15:03:13 by yait-kad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <unistd.h>
#include <stdlib.h>

char		*flags_d(t_str *tab, int i, char *result)
{
	char	*ptr;
	int		size;

	size = tab->width - i;
	i = 0;
	ptr = malloc(size + 1);
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

char		*char_d(t_str *tab, int nbr_len, char *nbr_str)
{
	char	*result;
	int		i;
	int		j;

	i = 0;
	j = 0;
	result = malloc(nbr_len);
	if (tab->value_d < 0)
	{
		result[i] = '-';
		i++;
		if ((tab->flags[1] != '0') || (tab->flags[1] == '0' && tab->width > 0))
			nbr_len = nbr_len - 2;
		else if (tab->precision >= nbr_len && tab->tst_prec == '.')
			nbr_len = nbr_len - 2;
		else
			nbr_len = nbr_len - 1;
	}
	if (tab->precision > nbr_len)
		while (i < (tab->precision - nbr_len))
			result[i++] = '0';
	while ((nbr_str[j] != '\0'))
		result[i++] = nbr_str[j++];
	result[i] = '\0';
	if (tab->width > nbr_len && tab->width > tab->precision)
		result = flags_d(tab, i, result);
	return (result);
}