/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-kad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 08:07:25 by yait-kad          #+#    #+#             */
/*   Updated: 2019/12/28 11:27:39 by yait-kad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

int			len_p(unsigned long nb)
{
	int		i;

	i = 1;
	while (nb >= 16)
	{
		nb = nb / 16;
		i++;
	}
	return (i);
}

char		*hex_p(unsigned long nb, char c)
{
	char		*result;
	int			i;
	int			modl;
	int			len;
	char		*tmp;

	len = len_p(nb);
	modl = 0;
	result = (char *)malloc(len + 1);
	i = 0;
	while (i < len)
	{
		modl = nb % 16;
		if (modl < 10)
			result[i++] = modl + 48;
		else
			result[i++] = modl + c - 33;
		nb = nb / 16;
	}
	result[i] = '\0';
	result = reverse(result, ft_strlen(result));
	tmp = result;
	result = ft_strjoin("0x", result);
	free(tmp);
	return (result);
}

void		pointer_p(t_str *tab)
{
	void			*ch;
	char			*nbr_str;
	unsigned long	rslt;
	char			*result;
	int				nbr_len;

	ch = va_arg(tab->ap, void *);
	rslt = (unsigned long)ch;
	if (rslt == 0 && tab->tst_prec == '.')
		nbr_str = "0x";
	else
		nbr_str = hex_p(rslt, 'x');
	nbr_len = ft_strlen(nbr_str);
	result = char_d(tab, nbr_len, nbr_str);
	tab->len = tab->len + ft_strlen(result);
	ft_putstr(result);
	free(result);
	if (!(rslt == 0 && tab->tst_prec == '.'))
		free(nbr_str);
	ch = (void *)0;
	rslt = 0;
	nbr_len = 0;
}
