/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugreyiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 17:55:34 by ugreyiro          #+#    #+#             */
/*   Updated: 2020/11/21 17:55:39 by ugreyiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		add_flag(t_format *format, char c)
{
	if (c == '0')
		format->flags |= FLG_ZER;
	else if (c == '-')
		format->flags |= FLG_MIN;
	else if (c == '#')
		format->flags |= FLG_HSH;
	else if (c == ' ')
		format->flags |= FLG_SPC;
	else if (c == '+')
		format->flags |= FLG_PLS;
}

void			parse_flags(t_format *format, const char *str)
{
	unsigned char	flags;
	int				i;

	i = format->length;
	format->flags = FLG_EMP;
	flags = FLG_EMP;
	while (str[i] == '-' || str[i] == '0' || str[i] == '#' ||
			str[i] == ' ' || str[i] == '+')
	{
		add_flag(format, str[i]);
		++i;
	}
	format->length = i;
}
