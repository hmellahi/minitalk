#include "minitalk.h"

static int	digit(int n)
{
	int	c;

	if (n == 0)
		return (1);
	c = 0;
	while (n)
	{
		c++;
		n /= 10;
	}
	return (c);
}

static char	*ft_itoa_healper(int a, char *str, int i)
{
	unsigned int	n;

	if (a < 0)
	{
		str[i++] = '-';
		n = -a;
	}
	else
		n = a;
	if (n < 10)
	{
		str[i] = n + '0';
	}
	else
	{
		ft_itoa_healper(n / 10, str, i);
		i += digit(n / 10);
		str[i] = n % 10 + '0';
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char			*str;
	int				i;
	int				len;

	len = digit(n);
	i = 0;
	if (n < 0)
		len++;
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	str[len] = 0;
	return (ft_itoa_healper(n, str, i));
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char const *str, int fd)
{
	if (!str)
		return ;
	while (*str)
	{
		ft_putchar_fd(*str, fd);
		str++;
	}
}
