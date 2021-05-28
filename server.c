#include "minitalk.h"

char binary_to_asc(t_string binary)
{
	char	rec;
	int		i;

	i = -1;
	rec = 0;
	while (++i < 8)
		rec = (rec << 1) + (binary[i] != '0');
 	return (rec);
}


int i;
t_string binary;
void    handle_signal(int signal)
{
	i++;
	if (signal == SIGUSR1)
		binary = str_join(binary, '1');
	else
		binary = str_join(binary, '0');
	if (i == 8)
	{
		i = 0;
		char c = binary_to_asc(binary);
		binary = "";
		ft_putchar_fd(c, 1);
	}
	x();
	// signal(SIGUSR1, handle_signal);
	// signal(SIGUSR2, handle_signal);
}

int main()
{
	pid_t pid;

	i = 0;
	binary = "";
	pid = getpid();
	ft_putstr_fd("SERVER PID: ", 1);
	ft_putstr_fd(ft_itoa(pid), 1);
	ft_putstr_fd("\n", 1);
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	while(1)
	{
		pause();
	}
}