/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_point.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 14:41:32 by aloubar           #+#    #+#             */
/*   Updated: 2021/03/09 11:02:00 by aloubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		get_len_hex(unsigned long long int nb)
{
	int len;

	len = 0;
	while (nb)
	{
		++len;
		nb = nb / 16;
	}
	return (len);
}

static void		ft_itoa_base(t_info *info, unsigned long long int nb,
		char *str_of_p)
{
	int		len;
	char	base[16];

	(!nb && info->bdot && !info->dot_exist) ? info->point_null = 1 : 0;
	(!nb && info->bdot && info->dot_exist) ? info->point_null = 2 : 0;
	ft_strcpy(base, "0123456789abcdef");
	len = get_len_hex(nb);
	if (!nb)
		len = 1;
	str_of_p[len] = '\0';
	while (len)
	{
		len--;
		str_of_p[len] = base[nb % 16];
		nb = nb / 16;
	}
}

static void		ft_ptr_if_dot(t_info *info, char *str_of_p, char *str_of_width)
{
	char	str_of_dot[600];

	if (info->width < info->dot)
	{
		info->width = info->dot;
		info->zero = 1;
	}
	str_of_width = ft_treat_width(info);
	if (info->minus == 1)
		ft_add_prec_display(info, str_of_p, str_of_dot, 1);
	if (info->width > info->dot && info->width)
	{
		if (info->minus == 0 && info->zero == 1)
		{
			ft_add_to_buff(info, "0x", 2);
			info->minus_done = 1;
		}
		ft_add_to_buff(info, str_of_width, info->len_width - 2);
	}
	if (info->minus == 0)
		ft_add_prec_display(info, str_of_p, str_of_dot, 1);
}

static void		ft_ptr_no_dot(t_info *info, char *str_of_p, char *str_of_width)
{
	if (info->width)
		str_of_width = ft_treat_width(info);
	if (info->minus == 1)
	{
		ft_add_to_buff(info, "0x", 2);
		info->minus_done = 1;
		ft_add_to_buff(info, str_of_p, info->len_variable);
	}
	if (info->width && info->width > info->len_variable)
	{
		if (info->minus_done == 0 && info->zero == 1)
		{
			ft_add_to_buff(info, "0x", 2);
			info->minus_done = 1;
		}
		ft_add_to_buff(info, str_of_width, info->len_width - 2);
	}
	if (info->minus == 0)
	{
		if (info->minus_done++ == 0)
			ft_add_to_buff(info, "0x", 2);
		ft_add_to_buff(info, str_of_p, info->len_variable);
	}
}

void			ft_treat_point(t_info *info, unsigned long long int nb)
{
	char	str_of_p[600];
	char	str_of_width[600];
	char	base[16];
	int		len;

	ft_bzero(str_of_p, 600);
	ft_bzero(base, 17);
	ft_strcpy(base, "0123456789abcdef");
	len = get_len_hex(nb);
	if (info->dot < 0)
	{
		info->flag_0 = 1;
		info->dot = 1;
	}
	ft_itoa_base(info, nb, str_of_p);
	info->len_variable = ft_strlen(str_of_p);
	if (info->bdot == 1)
		ft_ptr_if_dot(info, str_of_p, str_of_width);
	else if (info->bdot == 0)
		ft_ptr_no_dot(info, str_of_p, str_of_width);
}
