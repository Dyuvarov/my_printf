/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugreyiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 12:23:22 by ugreyiro          #+#    #+#             */
/*   Updated: 2020/11/17 12:23:24 by ugreyiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "libft.h"

void	parse_type(t_format *format, const char *str)
{
	int		i;
	char	type;

	type = 0;
	i = format->length;
	if (str[i] == 'c' || str[i] == 's' || str[i] == 'p' ||
		str[i] == 'd' || str[i] == 'i' || str[i] == 'u' ||
		str[i] == 'x' || str[i] == 'X' || str[i] == 'n' ||
		str[i] == 'f' || str[i] == 'g' || str[i] == 'e' ||
		str[i] == '%')
	{
		type = str[i];
		++i;
	}
	format->length = i;
	format->type = type;
}
