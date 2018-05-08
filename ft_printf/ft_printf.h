/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdubinki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 08:51:07 by vdubinki          #+#    #+#             */
/*   Updated: 2017/11/24 08:51:10 by vdubinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <wchar.h>

# include "libft.h"

# define RED		"\x1B[31m"
# define GREEN		"\x1B[32m"
# define YELLOW		"\x1B[33m"
# define BLUE		"\x1B[34m"
# define MAGENTA	"\x1B[35m"
# define CYAN		"\x1B[36m"
# define WHITE		"\x1B[37m"
# define RESET		"\x1B[0m"

# define FLAGS_COUNT	5

static char				g_flags[] =
{
	'-',
	'+',
	'0',
	' ',
	'#',
	0
};

# define LENGTH_MODIFIERS_COUNT 6

/*
** max length of each modifier is 2
*/

static char				*g_length_modifiers[] =
{
	"hh",
	"h",
	"ll",
	"l",
	"j",
	"z",
	0
};

static int				g_length_modifiers_priorities[] =
{
	4,
	5,
	2,
	3,
	0,
	1
};

typedef struct		s_options
{
	int				flags[FLAGS_COUNT];
	int				min_width;
	int				precision;
}					t_options;

typedef int			(*t_converter)(va_list ap,
									int length_modifier,
									t_options *options);

typedef struct		s_specifier
{
	char			symbol;
	int				length_modifiers[LENGTH_MODIFIERS_COUNT];
	t_converter		converter;
}					t_specifier;

int					s_converter(va_list ap,
									int length_modifier,
									t_options *options);

int					suc_converter(va_list ap,
									int length_modifier,
									t_options *options);

int					d_converter(va_list ap,
									int length_modifier,
									t_options *options);

int					duc_converter(va_list ap,
									int length_modifier,
									t_options *options);

int					u_converter(va_list ap,
									int length_modifier,
									t_options *options);

int					uuc_converter(va_list ap,
									int length_modifier,
									t_options *options);

int					p_converter(va_list ap,
									int length_modifier,
									t_options *options);

int					o_converter(va_list ap,
									int length_modifier,
									t_options *options);

int					ouc_converter(va_list ap,
									int length_modifier,
									t_options *options);

int					x_converter(va_list ap,
									int length_modifier,
									t_options *options);

int					xuc_converter(va_list ap,
									int length_modifier,
									t_options *options);

int					b_converter(va_list ap,
									int length_modifier,
									t_options *options);

int					buc_converter(va_list ap,
									int length_modifier,
									t_options *options);

int					c_converter(va_list ap,
									int length_modifier,
									t_options *options);

int					cuc_converter(va_list ap,
									int length_modifier,
									t_options *options);

static t_specifier			g_specifiers[] =
{
	{ 's', { 0, 0, 0, 1, 0, 0 }, s_converter},
	{ 'S', { 0, 0, 0, 0, 0, 0 }, suc_converter},
	{ 'd', { 1, 1, 1, 1, 1, 1 }, d_converter},
	{ 'i', { 1, 1, 1, 1, 1, 1 }, d_converter},
	{ 'D', { 0, 0, 0, 0, 0, 0 }, duc_converter},
	{ 'u', { 1, 1, 1, 1, 1, 1 }, u_converter},
	{ 'U', { 0, 0, 0, 0, 0, 0 }, uuc_converter},
	{ 'p', { 0, 0, 0, 0, 0, 0 }, p_converter},
	{ 'o', { 1, 1, 1, 1, 1, 1 }, o_converter},
	{ 'O', { 0, 0, 0, 0, 0, 0 }, ouc_converter},
	{ 'x', { 1, 1, 1, 1, 1, 1 }, x_converter},
	{ 'X', { 1, 1, 1, 1, 1, 1 }, xuc_converter},
	{ 'b', { 1, 1, 1, 1, 1, 1 }, b_converter},
	{ 'B', { 1, 1, 1, 1, 1, 1 }, buc_converter},
	{ 'c', { 0, 0, 0, 1, 0, 0 }, c_converter},
	{ 'C', { 0, 0, 0, 0, 0, 0 }, cuc_converter},
	{ 0, { 0 }, 0 }
};

int					ft_printf(const char *format, ...);

#endif
