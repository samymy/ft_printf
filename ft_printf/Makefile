#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vdubinki <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/02 12:56:23 by vdubinki          #+#    #+#              #
#    Updated: 2017/10/02 12:56:24 by vdubinki         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a

LIBDIR = libft

SRC = 	ft_printf.c \
		ft_wctomb.c \
		str_func.c \
		nbr_func.c \
		add_func.c \
		s_converter.c \
		suc_converter.c \
		d_converter.c \
		u_converter.c \
		p_converter.c \
		o_converter.c \
		x_converter.c \
		xuc_converter.c \
		b_converter.c \
		buc_converter.c \
		c_converter.c \
		other_converters.c \
		get_specifier.c \
		get_options.c

OBJ = $(SRC:.c=.o)

INC = *.h

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(OBJ): $(INC)

.c.o:
	@gcc $(FLAGS) -c $<

$(NAME): $(OBJ)
	@make -C libft/
	@ar rc $(NAME) $(OBJ) $(addprefix $(LIBDIR)/, $(notdir $(LIBDIR)/*.o))

clean:
	@make clean -C libft/
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C libft/
	@rm -f $(NAME)

re: fclean all
