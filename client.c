#include "minitalk.h"
#include <unistd.h>

void get_server_pid()
{
	pid_t pid;

	pid = getpid();

}

t_string ascToBinary(int c)
{
	t_string	binary_code;
	int			i;

	i = 8;
	binary_code = "";
	while (--i >= 0)
		binary_code = str_join(binary_code, (c & (1 << i)) ? '1' : '0');
 	return (binary_code);
}

char*	convert_str_to_binary(char *str)
{
	char	*binary;

	binary = "";
	while (*str)
	{
		binary = ft_strjoin(binary, ascToBinary(*str));
		str++;
	}
	return (binary);
}

void	send_signals(char* binary_str, pid_t server_pid)
{
	int	i;

	i = -1;
	while (binary_str[++i])
	{
		putchar(binary_str[i]);
		if (binary_str[i] == '1')
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		usleep(10);
	}
}

int main(int ac, char** av)
{
	int			server_pid;
	t_string	msg;
	t_string	encoded_msg;

	server_pid = ft_atoi(av[1]);
	msg = av[2];
	encoded_msg = convert_str_to_binary(msg);
	send_signals(encoded_msg, server_pid);
}