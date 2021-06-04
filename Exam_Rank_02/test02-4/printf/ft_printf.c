#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

void	ft_putnbr_base(long long num, int base)
{
	char	*dec = "0123456789";
	char	*hex = "0123456789abcdef";

	if (num < 0)
		num *= -1;
	if (num >= base)
	{
		ft_putnbr_base(num / base, base);
		ft_putnbr_base(num % base, base);
	}
	else
	{
		if (base == 10)
			write(1, &dec[num], 1);
		else if (base == 16)
			write(1, &hex[num], 1);
	}
}

int		ft_strlen(char *s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int		ft_numlen(int n)
{
	int		i;

	if (n < 0)
		n *= -1;
	if (n == 0)
		return (1);
	i = 0;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int		ft_hexlen(unsigned int n)
{
	int		i;

	if (n == 0)
		return (1);
	i = 0;
	while (n != 0)
	{
		n /= 16;
		i++;
	}
	return (i);
}

char	*ft_strndup(char *s, int len)
{
	char	*new_str;
	int		i;

	if (!(new_str = (char *)malloc(len + 1)))
		return (0);
	i = 0;
	while (s[i] && i < len)
	{
		new_str[i] = s[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

void	ft_putnstr(char *s, int len)
{
	int		i;

	i = 0;
	while (s[i] && i < len)
	{
		write(1, &s[i], 1);
		i++;
	}
}

char	*findsdx(char *s)
{
	int		i;

	i = 0;
	while (s[i] && ((s[i] >= '0' && s[i] <= '9') || s[i] == '.'))
		i++;
	if (s[i] >= 32 && s[i] <= 126)
	{
		if (s[i] == 's' || s[i] == 'd' || s[i] == 'x')
			return (s + i);
	}
	return (0);
}

int		printwithflag(va_list ap, char *f, char type)
{
	int		width;
	int		dot;
	int		precision;
	int		nprinted;
	int		i;

	width = 0;
	dot = 0;
	precision = 0;
	nprinted = 0;
	i = 0;
	while (f[i])
	{
		if ((f[i] >= '0' && f[i] <= '9') && !dot)
			width = width * 10 + f[i] - '0';
		else if (f[i] == '.')
			dot = 1;
		else if ((f[i] >= '0' && f[i] <= '9') && dot)
			precision = precision * 10 + f[i] - '0';
		i++;
	}

	int		num;
	unsigned int	unum;		/////////  자료형 신경써~~~~~~~~~~~~~
	char	*str;
	int		len;

	num = 0;
	unum = 0;
	len = 0;				///////// 변수를 나중에 선언했으면 초기화하는것도 잊지마!!!!!!!!
	if (type == 's')
	{
		if (!(str = va_arg(ap, char *)))
			str = "(null)";
		len = ft_strlen(str);
		if (dot)
		{
			if (precision > len)
				precision = len;
		}
		else					///////////////  else 빼먹지마 정밀도 있을때 없을때를 구분하는 거니까
			precision = len;
		i = 0;
		while (i < width - precision)
		{
			write(1, " ", 1);
			nprinted++;
			i++;
		}
		nprinted += precision;
		ft_putnstr(str, precision);
	}
	else if (type == 'd' || type == 'x')
	{
		if (type == 'd')
		{
			num = va_arg(ap, int);
			len = ft_numlen(num);
		}
		else if (type == 'x')
		{
			unum = va_arg(ap, unsigned int);
			len = ft_hexlen(unum);
		}
		if (num == 0 && unum == 0 && dot && precision == 0)
		{
			i = 0;
			while (i < width)
			{
				write(1, " ", 1);
				nprinted++;
				i++;
			}
			free(f);
			return (nprinted);
		}
		if (precision < len)	//////////// 빼먹지마~~~~~~~~
			precision = len;	////////////
		if (num < 0)
			precision++;
		i = 0;
		while (i < width - precision)
		{
			write(1, " " , 1);
			nprinted++;
			i++;
		}
		if (num < 0)
		{
			write(1, "-", 1);
			len++;
		}
		i = 0;
		while (i < precision - len)
		{
			write(1, "0", 1);
			i++;
		}
		nprinted += precision;
		if (type == 'd')
			ft_putnbr_base(num, 10);
		else if (type == 'x')
			ft_putnbr_base(unum, 16);
	}
	free(f);
	return (nprinted);
}

int		parse_format(va_list ap, char *s)
{
	int		ret;
	char	*type;
	char	*format;
	int		i;

	ret = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			type = findsdx(s + i + 1);
			if (type)
			{
				format = ft_strndup(s + i, (type + 1) - (s + i));
				ret += printwithflag(ap, format, *type);
				i += ((type) - (s + i));
			}
		}
		else
		{
			write(1, &s[i], 1);
			ret++;
		}
		i++;
	}
	return (ret);
}


int		ft_printf(const char *format, ...)
{
	int		ret;
	va_list	ap;

	va_start(ap, format);
	ret = parse_format(ap, (char *)format);
	va_end(ap);
	return (ret);
}
/*
int		main(void)
{
	ft_printf("[%2.3s][%3.2d][%5.5x]", "sdfsdf", 10, 11);
	return (0);
}*/