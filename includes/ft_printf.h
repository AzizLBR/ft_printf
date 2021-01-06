/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubar <aloubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 16:06:54 by aloubar           #+#    #+#             */
/*   Updated: 2021/01/04 17:23:53 by aloubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

# include <stdlib.h>
# include "libft.h"
# include <stdarg.h>

typedef	struct	 s_info
{
	va_list		args;
	int			width;
	int			precision;
	int			return_value;
	int			i;
	char		spe;
}				t_info;

#endif
