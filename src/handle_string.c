/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugreyiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 09:50:18 by ugreyiro          #+#    #+#             */
/*   Updated: 2020/11/18 09:50:19 by ugreyiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	len_with_accuracy(t_format format, char **str)
{
	int		str_len;
	char	*tmp;

	tmp = *str;
	str_len = (int)ft_strlen(tmp);
	if ((format.accuracy >= 0) && (format.accuracy < str_len))
	{
		tmp[format.accuracy] = '\0';
		str_len = format.accuracy;
	}
	return (str_len);
}

static char	*result_with_spaces(int len, int str_len, t_format format,
		char *str)
{
	char	*result;
	char	*spc_str;

	if (!(spc_str = space_str(len - str_len)))
	{
		free(str);
		return (NULL);
	}
	if (format.flags & FLG_MIN)
		result = ft_strjoin(str, spc_str);
	else
		result = ft_strjoin(spc_str, str);
	free(str);
	free(spc_str);
	return (result);
}

char		*handle_string(t_format format, va_list *params)
{
	char	*result;
	char	*str;
	char	*p_str;
	int		len;
	int		str_len;

	p_str = va_arg(*params, char*);
	if (!p_str)
		str = null_str();
	else
		str = ft_strdup(p_str);
	if (!str)
		return (NULL);
	str_len = len_with_accuracy(format, &str);
	len = (format.width > str_len) ? format.width : str_len;
	if (len > str_len)
		result = result_with_spaces(len, str_len, format, str);
	else
		result = str;
	return (result);
}
