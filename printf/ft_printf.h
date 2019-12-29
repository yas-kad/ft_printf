/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-kad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 14:20:21 by yait-kad          #+#    #+#             */
/*   Updated: 2019/12/28 11:13:45 by yait-kad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct		t_struct
{
	const char		*format;
	va_list			ap;
	char			*flags;
	int				width;
	int				precision;
	size_t			i;
	int				len;
	int				value_d;
	char			tst_prec;
}					t_str;

int					ft_printf(const char *frmt, ...);
int					ft_putchar(int c);
int					check(t_str *tab);
t_str				*check_flags(t_str *tab);
t_str				*check_width(t_str *tab);
t_str				*check_precision(t_str *tab);
t_str				*specification(t_str *tab);
void				char_c(t_str *tab);
void				charc(t_str *tab, char print);
void				ft_putstr(char *str);
void				string_s(t_str *tab);
char				*flags_d(t_str *tab, int i, char *result);
char				*char_d(t_str *tab, int	nbr_len, char *nbr_str);
void				decimal_d(t_str *tab);
void				unsigned_u(t_str *tab);
char				*reverse(char *str2, int i);
void				hex_x(t_str *tab, char ch);
void				percent(t_str *tab);
void				pointer_p(t_str *tab);

#endif
