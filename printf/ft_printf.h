/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-kad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 14:20:21 by yait-kad          #+#    #+#             */
/*   Updated: 2019/12/15 01:31:51 by yait-kad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <limits.h>

typedef struct t_struct
{
    const char    	*format;
    va_list     ap;
    char        *flags;
    int         width;
    int         precision;
	size_t		i;
    int         len;
}				t_str;

t_str       *check_flags(t_str *tab);
t_str       *check_width(t_str *tab);
t_str       *check_precision(t_str *tab);
t_str       *specification(t_str *tab);
void		char_c(t_str *tab);
void        ft_putstr(char *str);
void        string_s(t_str *tab);
void        decimal_d(t_str *tab);
#endif
