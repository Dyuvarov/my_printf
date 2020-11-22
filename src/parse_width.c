/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugreyiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 17:56:46 by ugreyiro          #+#    #+#             */
/*   Updated: 2020/11/21 17:56:49 by ugreyiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	parse_width(t_format *format, const char *str, va_list *params)
{
	int i;
	int width;

	i = format->length;
	width = 0;
	if (ft_isdigit(str[i]))
	{
		width = ft_atoi(&(str[format->length]));
		while (ft_isdigit(str[i]))
			++i;
	}
	else if (str[i] == '*')
	{
		width = va_arg(*params, int);
		++i;
	}
	if (width < 0)
	{
		format->flags |= FLG_MIN;
		format->flags &= (~FLG_ZER);
		width *= -1;
	}
	format->length = i;
	format->width = width;
}
