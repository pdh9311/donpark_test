/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donpark <donpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 05:29:14 by donpark           #+#    #+#             */
/*   Updated: 2021/05/02 05:29:15 by donpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include "./libft/libft.h"
# define ONLYDOT 2
# define DOTNUM 1
# define NODOT 0
# define YES 1
# define NO 0

typedef struct	s_info
{
	int			hyphen;
	int			zero;
	int			w_num;
	int			p_num;
	int			p_exist;
	int			p_star;
}				t_info;

void			init_info(t_info *info);
char			*manage_type(va_list ap, char *tag, t_info info, int *ret);
int				parse_format(va_list ap, char *format);
int				ft_printf(const char *format, ...);

char			*check_flag(char *tag, t_info *info);
int				w_p_star_num(va_list ap, char **tag, int *error, t_info *info);
char			*check_width(va_list ap, char *tag, t_info *info);
char			*check_precision(va_list ap, char *tag, t_info *info);
char			*check_info(va_list ap, char *tag, t_info *info);

int				apply_to_percent(char *tag, t_info info, int *ret);
int				apply_to_char(va_list ap, char *tag, t_info info, int *ret);
int				apply_to_str(va_list ap, char *tag, t_info info, int *ret);
int				apply_to_pointer(va_list ap, char *tag, t_info info, int *ret);

void			is_hyphen1(char *hy_zero, char *str, int blank, size_t len);
void			no_hyphen1(char *hy_zero, char *str, int blank, size_t len);
int				print_char(char *tag, char *str, t_info info, size_t len);

int				check_zero(t_info info, ssize_t num, int *ret);
int				apply_to_int(va_list ap, t_info info, int *ret);
int				apply_to_unint(va_list ap, t_info info, int *ret);
int				apply_to_hex(va_list ap, char *tag, t_info info, int *ret);

void			is_hyphen2(char *str, int width, int precnum, int sign);
void			no_hyphen2(char *str, int width, t_info info, int sign);
int				print_int(char *str, t_info info, int sign);

int				hexlen(size_t num);
char			*chg_to_hex(size_t num, char *tag);
#endif
