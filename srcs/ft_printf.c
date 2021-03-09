/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubar <aloubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 16:10:26 by aloubar           #+#    #+#             */
/*   Updated: 2021/02/24 16:24:43 by aloubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		ft_putflagtozero(t_info *info)
{
	info->zero = 0;
	info->minus = 0;
	info->star = 0;
	info->dot = 0;
	info->dot_exist = 1;
	info->bdot = 0;
	info->width = 0;
	info->len_variable = 0;
	info->len_width = 0;
	info->len_dot = 0;
	info->point_null = 0;
	info->minus_done = 0;
	info->flag_0 = 0;
	info->nb_neg = 0;
	info->spe = '\0';
}

static void		ft_parse_flags(t_info *info, const char *str)
{
	while (str[info->i])
	{
		if ((!(ft_check_type(str[info->i]))) &&
				(!(ft_check_flags(str[info->i]))) &&
				(!(ft_isdigit(str[info->i]))))
			break ;
		if (str[info->i] == '0' && info->minus == 0 && info->width == 0)
			info->zero = 1;
		if (str[info->i] == '-')
		{
			info->zero = 0;
			info->minus = 1;
		}
		(str[info->i] == '*') ? ft_parse_star(info) : 0;
		(str[info->i] == '.') ? ft_parse_dot(info, str) : 0;
		(ft_isdigit(str[info->i])) ? ft_parse_nb(info, str[info->i]) : 0;
		if (ft_check_type(str[info->i]))
		{
			info->spe = str[info->i];
			break ;
		}
		info->i++;
	}
}

static void		ft_exec_flags(t_info *info)
{
	if (info->spe == 'c')
		ft_treat_char(info, va_arg(info->args, int));
	else if (info->spe == 'd' || info->spe == 'i')
		ft_treat_int(info, va_arg(info->args, int));
	else if (info->spe == 'u')
		ft_treat_unsigned(info, va_arg(info->args, unsigned int));
	else if (info->spe == 's')
		ft_treat_string(info, va_arg(info->args, char *));
	else if (info->spe == '%')
		ft_treat_char(info, '%');
	else if (info->spe == 'x' || info->spe == 'X')
		ft_treat_hexa(info, va_arg(info->args, unsigned int));
	else if (info->spe == 'p')
		ft_treat_point(info, va_arg(info->args, unsigned long long int));
}

static int		ft_end(t_info *info, char *str)
{
	va_end(info->args);
	ft_display_buff(info);
	free(str);
	return (info->return_value);
}

int				ft_printf(const char *format, ...)
{
	t_info	info;
	char	*str;

	str = ft_strdup(format);
	info.i = 0;
	info.j = 0;
	info.return_value = 0;
	va_start(info.args, format);
	while (str && str[info.i])
	{
		ft_putflagtozero(&info);
		if (!str)
			break ;
		if (str[info.i - 1] == '%' && info.i != 0)
		{
			ft_parse_flags(&info, str);
			(ft_check_type(str[info.i])) ? ft_exec_flags(&info) :
				ft_buff_no_flags(&info, str[info.i]);
		}
		else if (str[info.i - 1] != '%' && str[info.i] != '%')
			ft_buff_no_flags(&info, str[info.i]);
		info.i++;
	}
	return (ft_end(&info, str));
}
