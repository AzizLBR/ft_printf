/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_managment.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 13:26:15 by aloubar           #+#    #+#             */
/*   Updated: 2021/02/17 10:17:46 by aloubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_buff_no_flags(t_info *info, char c)
{
	printf("Valeur de c : %c\n", c);
	info->buff[info->j] = c;
	if (info->j == 1024)
		ft_display_buff(info);
	info->j++;
	info->return_value++;
}

void	ft_add_to_buff(t_info *info, char *str, int len)
{
	int i;
	
	info->return_value += len;
	i = -1;
	while (++i < len)
	{
		if (info->j == 1024)
			ft_display_buff(info);
		info->buff[info->j++] = str[i];
	}
}

void	ft_display_buff(t_info *info)
{
	write(1, info->buff, info->j);
	info->j = 0;
}
