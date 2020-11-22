/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugreyiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 13:45:27 by ugreyiro          #+#    #+#             */
/*   Updated: 2020/11/18 13:45:29 by ugreyiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "libft.h"

static char		*int_to_hex(int len, unsigned int nbr)
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

static int		handle_acc(t_format format, int len, char **result)
{
	char	*str_to_add;
	char	*tmp;
	int		r_len;

	r_len = len;
	if ((format.accuracy >= 0) && (format.accuracy > len))
	{
		if (!(str_to_add = zero_str(format.accuracy - len)))
		{
			free(*result);
			return (-1);
		}
		tmp = *result;
		*result = ft_strjoin(str_to_add, *result);
		free(str_to_add);
		free(tmp);
		if (!(*result))
			return (-1);
		r_len = ft_strlen(*result);
	}
	return (r_len);
}

static int		free_it(char *ptr)
{
	if (ptr)
		free(ptr);
	return (-1);
}

static int		handle_width(t_format format, int len, char **result)
{
	char	*str_to_add;
	char	*tmp;

	if ((format.flags & FLG_ZER) && (format.accuracy < 0))
	{
		if (!(str_to_add = zero_str(format.width - len)))
			return (free_it(*result));
	}
	else
	{
		if (!(str_to_add = space_str(format.width - len)))
			return (free_it(*result));
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

char			*handle_hex(t_format format, va_list *params)
{
	char			*res;
	unsigned int	nbr;
	int				len;
	char			*tmp;

	nbr = va_arg(*params, unsigned int);
	len = hex_nbrlen(nbr);
	if (format.accuracy == 0 && nbr == 0)
		res = space_str(0);
	else
		res = int_to_hex(len, nbr);
	if (!res || (len = handle_acc(format, (int)ft_strlen(res), &res)) < 0)
		return (NULL);
	if ((format.flags & FLG_HSH) && (nbr != 0))
	{
		tmp = res;
		res = ft_strjoin("0x", res);
		free(tmp);
	}
	if (format.width > (int)ft_strlen(res))
	{
		if ((len = handle_width(format, (int)ft_strlen(res), &res)) < 0)
			return (NULL);
	}
	return (res);
}
