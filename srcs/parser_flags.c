/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 12:37:17 by aloubar           #+#    #+#             */
/*   Updated: 2021/02/19 14:53:14 by aloubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_info		*ft_parse_minus(t_info *info)
{
	info->zero = 0;
	info->minus = 1;
	return (info);
}

t_info		*ft_parse_star(t_info *info)
{
	info->star = 1;
	info->width = va_arg(info->args, int);
	if (info->width < 0)
	{
		info->minus = 1;
		info->width *= -1;
		info->zero = 0;
	}
	return (info);
}

t_info		*ft_parse_dot(t_info *info, const char *str)
{
	info->bdot = 1;
	if (ft_check_type(str[++info->i]))
		info->dot_exist = 0;
	if (str[info->i] == '*')
	{
		info->dot = va_arg(info->args, int);
		info->star = 1;
	}
	else
		while (ft_isdigit(str[info->i]))
			info->dot = (info->dot * 10) + ((int)str[info->i++] - 48);
	return (info);
}

t_info		*ft_parse_nb(t_info *info, char c)
{
	if (info->star == 1)
		info->width = 0;
	if (ft_isdigit(c))
		info->width = ((info->width * 10) + c - 48);
	return (info);
}
