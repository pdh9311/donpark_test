#include "ft_printf.h"

void	ft_init_info(t_info *info)
{
	info->f_hyphen = 0;
	info->f_zero = 0;
	info->w_num = 0;
	info->p_num = 0;
	info->p_existence = 0;
	info->p_asterisk = 0;
}
