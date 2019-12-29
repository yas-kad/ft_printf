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
#include "libft/libft.h"

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

char		*hex_p(t_str *tab, unsigned long nb, char c)
{
	char		*result;
	int			i;
	int			modl;
	int			len;
	char		*ptr;

	if (nb == 0 && tab->tst_prec == '.')
		result = "0x";
	else
	{
		len = len_p(nb);
		modl = 0;
		result = malloc(len + 1);
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
		result = ft_strjoin("0x", result);
	}
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
	nbr_str = hex_p(tab, rslt, 'x');
	nbr_len = ft_strlen(nbr_str);
	result = char_d(tab, nbr_len, nbr_str);
	tab->len = tab->len + ft_strlen(result);
	free(result);
	ft_putstr(result);
}
