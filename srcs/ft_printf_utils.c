/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 15:15:04 by aloubar           #+#    #+#             */
/*   Updated: 2021/02/24 15:31:58 by aloubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int				ft_check_type(char c)
{
	return (c == 's' || c == 'd' || c == 'c' || c == 'p' || c == '%' ||
			c == 'i' || c == 'u' || c == 'x' || c == 'X');
}

int				ft_check_flags(char c)
{
	return (c == '0' || c == '-' || c == '*' || c == '.');
}

static int		ft_get_size(long nb, t_info *info)
{
	size_t	size;
	long	tmp;

	size = 0;
	if (nb < 0)
		nb = -nb;
	tmp = nb;
	while (tmp > 0)
	{
		tmp = tmp / 10;
		size++;
	}
	if (nb == 0 && size == 0 && info->dot_exist == 1 && info->bdot == 0)
		size = 1;
	return (size);
}

void			ft_itoa_remixed(long long int nb, char *str, t_info *info)
{
	size_t	size;

	if ((info->spe == 'i' || info->spe == 'd') &&
			(nb > 2147483647 || nb < -2147483648))
		return ;
	ft_bzero(str, 12);
	if (nb < 0)
		nb = -nb;
	size = ft_get_size(nb, info);
	str[size] = '\0';
	while (size-- > 0)
	{
		str[size] = (nb % 10) + 48;
		nb = nb / 10;
	}
}

char			*ft_strcpy(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = 0;
	return (s1);
}
