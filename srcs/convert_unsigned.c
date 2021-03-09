/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 13:20:04 by aloubar           #+#    #+#             */
/*   Updated: 2021/03/09 11:02:30 by aloubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		ft_u_if_dot(t_info *info, char *str_u, char *str_of_width)
{
	char	str_of_dot[600];

	if (info->width < info->dot)
	{
		info->width = info->dot;
		info->zero = 1;
	}
	str_of_width = ft_treat_width(info);
	if (info->minus == 1)
		ft_add_prec_display(info, str_u, str_of_dot, 1);
	if (info->width > info->dot)
		ft_add_to_buff(info, str_of_width, info->len_width);
	if (info->minus == 0)
		ft_add_prec_display(info, str_u, str_of_dot, 1);
}

static void		ft_u_if_no_dot(t_info *info, char *str_u, char *str_of_width)
{
	if (info->width)
		str_of_width = ft_treat_width(info);
	if (info->minus == 1)
		ft_add_to_buff(info, str_u, info->len_variable);
	ft_add_to_buff(info, str_of_width, info->len_width);
	if (info->minus == 0)
		ft_add_to_buff(info, str_u, info->len_variable);
}

void			ft_treat_unsigned(t_info *info, unsigned int nb)
{
	char	str_u[33];
	char	str_of_width[600];

	ft_bzero(str_u, 33);
	if (info->dot < 0)
	{
		info->dot = 1;
		info->flag_0 = 1;
	}
	ft_itoa_remixed(nb, str_u, info);
	info->len_variable = (int)ft_strlen(str_u);
	if (info->bdot == 1)
		ft_u_if_dot(info, str_u, str_of_width);
	else if (info->bdot == 0)
		ft_u_if_no_dot(info, str_u, str_of_width);
}
