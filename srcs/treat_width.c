/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 15:32:31 by aloubar           #+#    #+#             */
/*   Updated: 2021/02/21 16:02:18 by aloubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_treat_width(t_info *info, char *str)
{
	int		i;
	
	ft_bzero(str, 600);
	if ((info->spe == 'd' && info->bdot == 1 && info->dot >= 0)
				|| (info->spe == 'i' && info->bdot == 1 && info->dot >= 0))
		info->zero = 0;
	if ((info->spe == 'd' && info->len_variable == 0 &&
		info->width > info->dot) || (info->spe == 'i' &&
		info->len_variable == 0 && info->width > info->dot))
		info->width = info->width - info->dot;
	if ((info->spe == 'd' && info->nb_neg == 1) || (info->spe == 'i' &&
				info->nb_neg == 1))
		info->width--;
	if (info->dot >= 0 && info->spe == 's' && info->dot < info->width
		&& info->bdot == 1)
	{
		if (info->len_variable == 0)
			i = info->width;
		else
			i = info->width - info->dot;
	}
	else
		i = info->width - info->len_variable;
	while (info->len_width < i)
	{
		if (info->zero)
			str[info->len_width] = '0';
		else
			str[info->len_width] = ' ';
		info->len_width++;
	}
	if (info->spe == 'c' || info->spe == '%')
		info->len_width--;
}
