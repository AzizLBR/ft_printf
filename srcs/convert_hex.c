/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 13:47:46 by aloubar           #+#    #+#             */
/*   Updated: 2021/03/09 11:01:34 by aloubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		get_len_hex(unsigned int nb)
{
	unsigned int	n;
	int				len;

	len = 0;
	n = nb;
	while (n > 0)
	{
		++len;
		n = n / 16;
	}
	return (len);
}

static void		ft_itoa_base(t_info *info, unsigned int nb, char *str_h)
{
	int		len;
	char	base[16];

	(!nb && info->bdot && !info->dot_exist) ? info->point_null = 1 : 0;
	(!nb && info->bdot && info->dot_exist) ? info->point_null = 2 : 0;
	if (info->spe == 'x')
		ft_strcpy(base, "0123456789abcdef");
	else if (info->spe == 'X')
		ft_strcpy(base, "0123456789ABCDEF");
	len = get_len_hex(nb);
	if (!nb)
		len = 1;
	str_h[len] = '\0';
	while (len)
	{
		len--;
		str_h[len] = base[nb % 16];
		nb = nb / 16;
	}
}

static void		ft_hex_if_dot(t_info *info, char *str_h, char *str_of_width)
{
	char	str_of_dot[600];

	if (info->width < info->dot)
	{
		info->width = info->dot;
		info->zero = 1;
	}
	str_of_width = ft_treat_width(info);
	if (info->minus == 1)
		ft_add_prec_display(info, str_h, str_of_dot, 1);
	if (info->width > info->dot)
		ft_add_to_buff(info, str_of_width, info->len_width);
	if (info->minus == 0)
		ft_add_prec_display(info, str_h, str_of_dot, 1);
}

static void		ft_hex_if_no_dot(t_info *info, char *str_h, char *str_of_width)
{
	if (info->width)
		str_of_width = ft_treat_width(info);
	if (info->minus == 1)
		ft_add_to_buff(info, str_h, info->len_variable);
	ft_add_to_buff(info, str_of_width, info->len_width);
	if (info->minus == 0)
		ft_add_to_buff(info, str_h, info->len_variable);
}

void			ft_treat_hexa(t_info *info, unsigned int nb)
{
	char	str_h[33];
	char	str_of_width[600];

	ft_bzero(str_h, 33);
	if (info->dot < 0)
	{
		info->dot = 1;
		info->flag_0 = 1;
	}
	ft_itoa_base(info, nb, str_h);
	info->len_variable = (int)ft_strlen(str_h);
	if (info->bdot == 1)
		ft_hex_if_dot(info, str_h, str_of_width);
	else if (info->bdot == 0)
		ft_hex_if_no_dot(info, str_h, str_of_width);
}
