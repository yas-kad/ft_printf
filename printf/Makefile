# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yait-kad <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/23 14:53:39 by yait-kad          #+#    #+#              #
#    Updated: 2019/12/23 15:31:11 by yait-kad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a

SOURCES =	ft_printf.c\
			char_c.c\
			check.c\
			decimal_d.c\
			hex.c\
			percent\
			pointer_p.c\
			specification.c\
			string_s.c\
			unsinged_u.c\
			libft/ft_strlen.c\
			libft/ft_strjoin.c\
			libft/ft_itoa.c\
			libft/ft_strdup.c\
			libft/ft_uitoa.c\
			libft/ft_strcmp.c\

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
