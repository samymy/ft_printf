/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_func.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdubinki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 10:30:35 by vdubinki          #+#    #+#             */
/*   Updated: 2017/12/14 10:30:37 by vdubinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STR_FUNC_H
# define STR_FUNC_H

# include <unistd.h>
# include <stdlib.h>

# include "libft.h"

void			ft_swap(char *s1, char *s2);
int				ft_nputstr(char *str);
int				ft_putfillers(char filler, int n);
char			*ft_itoabase(uintmax_t nbr, int base, int uppercase);
int				ft_natoi(const char *str);

#endif
