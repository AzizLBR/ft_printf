/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 15:32:31 by aloubar           #+#    #+#             */
/*   Updated: 2021/03/09 11:14:01 by aloubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		ft_special_cases(t_info *info)
{
	if ((info->spe == 'd' || info->spe == 'i' || info->spe == 'p' ||
			info->spe == 'u' || info->spe == 'x' || info->spe == 'X') &&
			info->bdot && info->dot >= 0 && info->flag_0 == 0)
		info->zero = 0;
	if (info->point_null == 1 || info->point_null == 2)
		info->len_variable = 0;
	if ((info->spe == 'd' || info->spe == 'i' || info->spe == 'p' ||
			info->spe == 'u' || info->spe == 'x' || info->spe == 'X') &&
			info->len_variable == 0 && info->width > info->dot)
		info->width = info->width - info->dot;
	if ((info->spe == 'd' || info->spe == 'i') && info->nb_neg == 1)
		info->width--;
}

char			*ft_treat_width(t_info *info)
{
	int		i;
	char	*str;

	//ft_bzero(str, 600);
	str = NULL;
	ft_special_cases(info);
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
	if ((str = malloc(sizeof(char) * (i + 1))) == NULL)
		return NULL;
	str[i] = '\0';
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
	return (str);
}
