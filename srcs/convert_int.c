/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 13:36:19 by aloubar           #+#    #+#             */
/*   Updated: 2021/02/21 16:00:27 by aloubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		ft_precision(t_info *info, char *str_of_dot)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	ft_bzero(str_of_dot, 600);
	if (info->dot_exist == 0)
		return ;
	if (info->dot > info->len_variable)
		i = info->dot - info->len_variable;
	info->len_dot = i;
	while (i > 0)
	{
		str_of_dot[j] = '0';
		i--;
		j++;
	}
}

static void		ft_add_prec_display(t_info *info, char *str, char *str_of_dot,
		int nb)
{
		if (nb < 0 && info->minus_done == 0)
		{
			ft_add_to_buff(info, "-", 1);
			info->minus_done = 1;
		}
		ft_precision(info, str_of_dot);
		ft_add_to_buff(info, str_of_dot, info->len_dot);
		ft_add_to_buff(info, str, info->len_variable);
}

static void		ft_int_if_dot(t_info *info, char *str, char *str_of_width,
		int nb)
{
	char	str_of_dot[600];
	
	if (info->width < info->dot)
	{
		info->width = info->dot;
		info->zero = 1;
	}
	ft_treat_width(info, str_of_width);
	if (info->minus == 1)
		ft_add_prec_display(info, str, str_of_dot, nb);
	if (info->zero == 1 && info->minus_done == 0 && nb < 0)
	{
		info->minus_done = 1;
		ft_add_to_buff(info, "-", 1);
	}
	if ((info->zero == 0 && info->width > info->dot)
			|| (info->zero == 1 && info->width > info->dot))
		ft_add_to_buff(info, str_of_width, info->len_width);
	if (info->minus == 0)
		ft_add_prec_display(info, str, str_of_dot, nb);
}

static void		ft_int_no_dot(t_info *info, char *str_of_int,
		char *str_of_width, int nb)
{
	if (info->width)
		ft_treat_width(info, str_of_width);
	if (info->minus == 1)
	{
		if (nb < 0)
		{
			info->minus_done = 1;
			ft_add_to_buff(info, "-", 1);
		}
		ft_add_to_buff(info, str_of_int, info->len_variable);
	}
	if (info->zero == 1 && info->minus_done == 0 && nb < 0)
	{
		info->minus_done = 1;
		ft_add_to_buff(info, "-", 1);
	}
	ft_add_to_buff(info, str_of_width, info->len_width);
	if (info->minus == 0)
	{
		if (nb < 0 && info->minus_done == 0)
			ft_add_to_buff(info, "-", 1);
		ft_add_to_buff(info, str_of_int, info->len_variable);
	}
}

void			ft_treat_int(t_info *info, int nb)
{
	char	str_of_int[12];
	char	str_of_width[600];
	
	ft_itoa_remixed(nb, str_of_int, info);
	info->len_variable = (int)ft_strlen(str_of_int);
	if (nb < 0)
		info->nb_neg = 1;
	if (info->bdot == 1)
		ft_int_if_dot(info, str_of_int, str_of_width, nb);
	else if (info->bdot == 0)
		ft_int_no_dot(info, str_of_int, str_of_width, nb);
}
