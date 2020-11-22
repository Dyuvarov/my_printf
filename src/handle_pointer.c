/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_poinetr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugreyiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 12:59:46 by ugreyiro          #+#    #+#             */
/*   Updated: 2020/11/18 12:59:49 by ugreyiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int		hex_long_nbrlen(long nbr)
{
	int	i;

	if (nbr == 0)
		return (1);
	i = 0;
	while (nbr > 0)
	{
		nbr /= 16;
		++i;
	}
	return (i);
}

static char		*long_to_hex(int len, long nbr)
{
	char	*result;
	char	*base;

	base = "0123456789abcdef";
	if (!(result = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	result[len] = '\0';
	if (nbr == 0)
		result[0] = base[0];
	while (len > 0)
	{
		result[--len] = base[nbr % 16];
		nbr /= 16;
	}
	return (result);
}

static int		handle_width(t_format format, int len, char **result)
{
	char	*str_to_add;
	char	*tmp;

	if (!(str_to_add = space_str(format.width - len)))
	{
		free(*result);
		return (-1);
	}
	tmp = *result;
	if (format.flags & FLG_MIN)
		*result = ft_strjoin(*result, str_to_add);
	else
		*result = ft_strjoin(str_to_add, *result);
	free(tmp);
	free(str_to_add);
	return (1);
}

char			*handle_pointer(t_format format, va_list *params)
{
	char	*result;
	long	nbr;
	int		len;
	char	*tmp;

	nbr = va_arg(*params, long);
	len = hex_long_nbrlen(nbr);
	if (nbr == 0 && format.accuracy == 0)
		result = space_str(0);
	else
		result = long_to_hex(len, nbr);
	if (!result)
		return (NULL);
	tmp = result;
	result = ft_strjoin("0x", result);
	free(tmp);
	len = ft_strlen(result);
	if (format.width > len)
	{
		if ((len = handle_width(format, len, &result)) < 0)
			return (NULL);
	}
	return (result);
}
