/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugreyiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 13:51:26 by ugreyiro          #+#    #+#             */
/*   Updated: 2020/11/22 14:48:57 by ugreyiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <stdlib.h>
# include <stddef.h>

# define FLG_EMP 0b00000000
# define FLG_ZER 0b00000001
# define FLG_MIN 0b00000010
# define FLG_HSH 0b00000100
# define FLG_SPC 0b00001000
# define FLG_PLS 0b00010000

typedef struct
{
	unsigned char	flags;
	int				width;
	int				accuracy;
	unsigned int	length;
	char			type;
}					t_format;

int					ft_printf(const char *str, ...);
char				*space_str(int	n);
char				*zero_str(int n);
int					dec_nbrlen(int nbr);
int					hex_nbrlen(unsigned int nbr);
char				*null_str(void);
char				*add_smb(char *str, int num, char smb, int pos);
void				parse_flags(t_format *format, const char *str);
t_format			parse(const char *str, va_list *params);
void				parse_width(t_format *format, const char *str,
		va_list *params);
void				parse_accuracy(t_format *format, const char *str,
		va_list *params);
void				parse_type(t_format *format, const char *str);
char				*handle_format(t_format format, va_list *params);
char				*handle_char(t_format format, va_list *params);
char				*handle_string(t_format format, va_list *params);
char				*handle_hex(t_format format, va_list *params);
char				*handle_upper_hex(t_format format, va_list *params);
char				*handle_pointer(t_format format, va_list *params);
char				*handle_percent(t_format format);
char				*handle_int(t_format format, va_list *params);
char				*handle_uint(t_format format, va_list *params);

#endif
