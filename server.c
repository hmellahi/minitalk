#include "minitalk.h"

char	binary_to_asc(t_string binary)
{
	char	rec;
	int		i;

	i = -1;
	rec = 0;
	while (++i < 8)
		rec = (rec << 1) + (binary[i] != '0');
	return (rec);
}

void	handle_signal(int signal)
{
	static int		i;
	static t_string	binary;

	if (binary == NULL)
		binary = ft_strdup("");
	i++;
	if (signal == SIGUSR1)
		binary = str_join(binary, '1');
	else
		binary = str_join(binary, '0');
	if (i == 8)
	{
		i = 0;
		ft_putchar_fd(binary_to_asc(binary), 1);
		free(binary);
		binary = ft_strdup("");
	}
}

int	main(void)
{
	t_string	pid_str;

	pid_str = ft_itoa(getpid());
	ft_putstr_fd("SERVER PID: ", 1);
	ft_putstr_fd(pid_str, 1);
	ft_putstr_fd("\n", 1);
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	while (1)
		pause();
}
