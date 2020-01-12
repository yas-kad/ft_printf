# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yait-kad <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/23 14:53:39 by yait-kad          #+#    #+#              #
#    Updated: 2020/01/02 14:41:05 by yait-kad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SOURCES =	ft_printf.c\
			check_flags.c\
			check_width.c\
			ft_putstr.c\
			reverse.c\
			charc.c\
			char_c.c\
			check.c\
			char_d.c\
			decimal_d.c\
			hex.c\
			percent.c\
			pointer_p.c\
			specification.c\
			string_s.c\
			unsinged_u.c\
			ft_strlen.c\
			ft_strjoin.c\
			ft_itoa.c\
			ft_strdup.c\
			ft_uitoa.c\
			ft_strcmp.c\

OBJECT = $(SOURCES:.c=.o)

all : $(NAME)
$(NAME) : $(OBJECT)
	ar rc $(NAME) $^
	ranlib $(NAME)
%.o: %.c
	gcc -Wall -Wextra -Werror -c $< -o $@
clean :
	rm -rf $(OBJECT)

fclean: clean
	rm -rf $(NAME)
re: fclean all
