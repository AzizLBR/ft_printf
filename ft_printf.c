/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubar <aloubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 16:10:26 by aloubar           #+#    #+#             */
/*   Updated: 2021/01/04 17:31:26 by aloubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"
# include "libft.h"
void	ft_putstr(char *str)
{
	int i; 

	i = -1;
	while (str[i++])
		write(1, &str[i], 1);
}

void	ft_display_char(t_info *info)
{
	char c;

	c = (char)va_arg(info->args, int);
	write(1, &c, 1);
	info->return_value++;
}

void	ft_display_str(t_info *info)
{
	char *str;

	str = (char *)va_arg(info->args, char *);
	ft_putstr(str);
}

void	ft_display_int(t_info *info)
{
	int nb;

	nb = (int)va_arg(info->args, int);
	if (nb < 0 && info->spe == 'i')
		return ;
	ft_putnbr_fd(nb, 1);
}
int		ft_parsing(t_info *info, char *str)
{
	info->spe = str[info->i];
	if (str[info->i] == 'c')
		ft_display_char(info);
	else if (str[info->i] == 'd' || str[info->i] == 'i')
		ft_display_int(info);
//	else if (str[info->i] == 'x' || str[info->i] == 'X' || str[info->i] == u)

	else if (str[info->i] == 's')
		ft_display_str(info);
//	else if (str[info->i] == 'p')

	return (1);
}

int		ft_printf(const char *str, ...)
{
	t_info	info;

	info.i = 0;
	info.return_value = 0;
	va_start(info.args, str);
	while (str && str[info.i])
	{
		if (str[info.i - 1] == '%' && info.i != 0)
		{
			if (ft_parsing(&info, (char *)str) < 0)
				return (-1);
		}
		else if (str[info.i - 1] != '%' && str[info.i] != '%')
		{
			write(1, &str[info.i], 1);
			info.return_value++;
		}
		info.i++;
	}
	va_end(info.args);
	return (info.return_value);
}
