/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_func.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdubinki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 10:53:14 by vdubinki          #+#    #+#             */
/*   Updated: 2017/12/14 10:53:16 by vdubinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NBR_FUNC_H
# define NBR_FUNC_H

# include <unistd.h>
# include <stdlib.h>

# include "libft.h"
# include "add_func.h"

void			ft_putsnbr(intmax_t n);
void			ft_putunbr(uintmax_t n);
size_t			ft_snbrlen(intmax_t n);
size_t			ft_unbrlen(uintmax_t n);

#endif
