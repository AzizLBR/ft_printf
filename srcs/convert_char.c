/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 13:11:51 by aloubar           #+#    #+#             */
/*   Updated: 2021/02/17 10:25:06 by aloubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_treat_char(t_info *info, int c)
{
	char	*str;
	char	*str_of_width;
	
	str_of_width = ft_treat_width(info);
	printf("valeur de str_of_width : %s\n", str_of_width);
	str = (char *)malloc(sizeof(char) * (100));
	str[0] = (char)c;
	str[1] = '\0';
	info->len_variable = 1;
	if (info->minus == 1)
		ft_add_to_buff(info, str, 1);
	ft_add_to_buff(info, str_of_width, info->len_width);
	if (info->minus == 0)
		ft_add_to_buff(info, str, 1);
	free(str);
}
