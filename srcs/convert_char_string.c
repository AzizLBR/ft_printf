/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_char_string.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 13:11:51 by aloubar           #+#    #+#             */
/*   Updated: 2021/03/09 11:10:11 by aloubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void			ft_treat_char(t_info *info, int c)
{
	char	str[2];
	char	*str_of_width;

	if (info->width)
		str_of_width = ft_treat_width(info);
	str[0] = (char)c;
	str[1] = '\0';
	info->len_variable = 1;
	if (info->minus == 1)
		ft_add_to_buff(info, str, 1);
	ft_add_to_buff(info, str_of_width, info->len_width);
	if (info->minus == 0)
		ft_add_to_buff(info, str, 1);
	free(str_of_width);
}

static void		ft_add_to(t_info *info, char *str)
{
	if (info->dot >= info->len_variable || info->dot < 0)
		ft_add_to_buff(info, str, info->len_variable);
	else if (info->dot < info->len_variable)
		ft_add_to_buff(info, str, info->dot);
}

static void		ft_string_if_dot(t_info *info, char *str, char *str_of_width)
{
	if (info->width)
		str_of_width = ft_treat_width(info);
	if (info->minus == 1)
		ft_add_to(info, str);
	ft_add_to_buff(info, str_of_width, info->len_width);
	if (info->minus == 0)
		ft_add_to(info, str);
}

void			ft_treat_string(t_info *info, char *str)
{
	char	*str_of_width;

	if (str == NULL)
		str = "(null)";
	info->len_variable = (int)ft_strlen(str);
	if (info->bdot == 1 && info->dot == 0 && info->width == 0)
		return ;
	if (info->bdot == 1)
		ft_string_if_dot(info, str, str_of_width);
	else if (info->bdot == 0 || (info->bdot == 1 && info->dot == 0))
	{
		if (info->width)
			str_of_width = ft_treat_width(info);
		if (info->minus == 1)
			ft_add_to_buff(info, str, info->len_variable);
		ft_add_to_buff(info, str_of_width, info->len_width);
		if (info->minus == 0)
			ft_add_to_buff(info, str, info->len_variable);
	}
}
