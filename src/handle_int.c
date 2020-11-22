/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugreyiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 16:09:07 by ugreyiro          #+#    #+#             */
/*   Updated: 2020/11/19 16:09:08 by ugreyiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static char	*add_sign(t_format format, char *str, int nbr)
{
	char	*result;

	if ((format.flags & FLG_PLS) && (nbr >= 0))
	{
		result = ft_strjoin("+", str);
		free(str);
	}
	else if ((format.flags & FLG_SPC) && (nbr >= 0))
	{
		result = ft_strjoin(" ", str);
		free(str);
	}
	else if (nbr < 0)
	{
		result = ft_strjoin("-", str);
		free(str);
	}
	else
		result = str;
	return (result);
}

static char	*add_zero(char *str, t_format format, int nbr)
{
	char	*result;
	int		num;

	if (nbr >= 0)
		num = format.width - ft_strlen(str);
	else
		num = format.width - ft_strlen(str) - 1;
	result = add_smb(str, num, '0', 0);
	return (result);
}

char		*handle_int(t_format format, va_list *params)
{
	char			*result;
	int				nbr;

	nbr = va_arg(*params, int);
	if (format.accuracy == 0 && nbr == 0)
		result = space_str(0);
	else
		result = ft_itoa((nbr >= 0 ? nbr : -(long)nbr));
	if (format.accuracy > 0)
		result = add_smb(result,
				format.accuracy - (int)ft_strlen(result), '0', 0);
	if (!result)
		return (NULL);
	if ((format.flags & FLG_ZER) && (format.accuracy < 0))
	{
		if (!(result = add_zero(result, format, nbr)))
			return (NULL);
	}
	if (!(result = add_sign(format, result, nbr)))
		return (NULL);
	else if (format.flags & FLG_MIN)
		result = add_smb(result, format.width - (int)ft_strlen(result), ' ', 1);
	else
		result = add_smb(result, format.width - (int)ft_strlen(result), ' ', 0);
	return (result);
}
