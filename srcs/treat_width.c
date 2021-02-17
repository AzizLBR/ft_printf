/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 15:32:31 by aloubar           #+#    #+#             */
/*   Updated: 2021/02/17 09:41:44 by aloubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_treat_width(t_info *info)
{
	char	*str;
	int		i;

	i = info->width - info->len_variable;
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	while (info->len_width < i)
	{
		if (info->zero)
			str[info->len_width] = '0';
		else
			str[info->len_width] = ' ';
		info->len_width++;
	}
	str[info->len_width] = '\0';
	info->len_width--;
	return (str);
}
