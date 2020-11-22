/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_accurancy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugreyiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 11:49:59 by ugreyiro          #+#    #+#             */
/*   Updated: 2020/11/17 11:50:00 by ugreyiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "libft.h"

void	parse_accuracy(t_format *format, const char *str, va_list *params)
{
	int	i;
	int	accuracy;

	i = format->length;
	accuracy = -1;
	if (str[i] == '.')
	{
		i++;
		if (ft_isdigit(str[i]))
		{
			accuracy = ft_atoi(&str[i]);
			while (ft_isdigit(str[i]))
				++i;
		}
		else if (str[i] == '*')
		{
			accuracy = va_arg(*params, int);
			++i;
		}
		else
			accuracy = 0;
	}
	format->length = i;
	format->accuracy = accuracy;
}
