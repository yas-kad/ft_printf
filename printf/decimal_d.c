/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-kad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 18:13:50 by yait-kad          #+#    #+#             */
/*   Updated: 2019/12/28 10:46:02 by yait-kad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <unistd.h>
#include <stdlib.h>

void		decimal_d(t_str *tab)
{
	int		nbr_len;
	char	*nbr_str;
	char	*result;
	int		nbr;

	if (tab->tst_prec != '.' && tab->flags[1] == '0')
	{
		tab->precision = tab->width;
		tab->width = 0;
	}
	nbr = va_arg(tab->ap, int);
	nbr_str = ft_itoa(nbr);
	nbr_len = ft_strlen(nbr_str);
	if (nbr < 0)
	{
		nbr_str = ft_strdup(&*nbr_str + 1);
		tab->value_d = nbr;
	}
	if (tab->precision == 0 && nbr == 0)
		nbr_str[0] = '\0';
	result = char_d(tab, nbr_len, nbr_str);
	tab->len = tab->len + ft_strlen(result);
	free(nbr_str);
	free(result);
	ft_putstr(result);
}
