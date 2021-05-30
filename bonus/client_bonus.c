#include "../minitalk.h"
#include <unistd.h>

t_string	ascToBinary(int c)
{
	t_string	binary_code;
	int			i;
	char		a;
	t_string	tmp;

	i = 8;
	binary_code = ft_strdup("");
	while (--i >= 0)
	{
		if (c & (1 << i))
			a = '1';
		else
			a = '0';
		binary_code = str_join(binary_code, a);
	}
	return (binary_code);
}

char	*convert_str_to_binary(char *str)
{
	char	*binary;
	char	*b;

	binary = ft_strdup("");
	while (*str)
	{
		b = ascToBinary(*str);
		binary = ft_strjoin(binary, b, "11");
		str++;
	}
	return (binary);
}

void	send_signals(char *binary_str, pid_t server_pid)
{
	int	i;

	i = -1;
	while (binary_str[++i])
	{
		if (binary_str[i] == '1')
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		usleep(100);
	}
}

int	main(int ac, char **av)
{
	int			server_pid;
	t_string	client_pid;
	t_string	msg;
	t_string	encoded_msg;

	if (ac != 3)
	{
		ft_putstr_fd("client needs 2 args: SERVER_PID | MSG", 2);
		exit(1);
	}
	server_pid = ft_atoi(av[1]);
	if (server_pid < 0)
	{
		ft_putstr_fd("wt are u doing step bruh ;)\n"
			"PID must be positive", 2);
		exit(1);
	}
	client_pid = ft_itoa(getpid());
	msg = ft_strjoin("client[", client_pid, "01");
	msg = ft_strjoin(msg, "] > ", "10");
	msg = ft_strjoin(msg, av[2], "10");
	msg = ft_strjoin(msg, "\n", "10");
	encoded_msg = convert_str_to_binary(msg);
	send_signals(encoded_msg, server_pid);
	free(encoded_msg);
}
