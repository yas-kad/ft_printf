/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsinged_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-kad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 04:25:09 by yait-kad          #+#    #+#             */
/*   Updated: 2019/12/28 13:05:23 by yait-kad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void		unsigned_u(t_str *tab)
{
	int				nbr_len;
	char			*nbr_str;
	char			*result;
	unsigned int	nbr;

	if (tab->tst_prec != '.' && tab->flags[1] == '0' && tab->flags[0] != '-')
	{
		tab->precision = tab->width;
		tab->width = 0;
	}
	nbr = va_arg(tab->ap, unsigned int);
	nbr_str = ft_uitoa(nbr);
	nbr_len = ft_strlen(nbr_str);
	if (tab->precision == 0 && nbr == 0)
		nbr_str[0] = '\0';
	result = char_d(tab, nbr_len, nbr_str);
	tab->len = tab->len + ft_strlen(result);
	free(nbr_str);
	free(result);
	ft_putstr(result);
}
