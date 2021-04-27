#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include "./libft/libft.h"
# include <stdio.h>

typedef struct	s_info
{
	int			minus;
	int			zero;
	int			width;
	int			w_asterisk;
	int			dot;
	int			precision;
	int			p_asterisk;
	char		type;
}				t_info;

#endif
