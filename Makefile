client_name = client
server_name = server
bonus_client_name = client_bonus
NAME=fsd
all: ${client_name} ${server_name}

${client_name}:
	gcc client.c utils.c utils2.c -o client

${server_name}:
	gcc server.c utils.c utils2.c -o server

bonus: ${server_name} ${bonus_client_name}

${bonus_client_name}:
	gcc bonus/client_bonus.c utils.c utils2.c -o client_bonus

clean:

fclean: clean
	rm -rf ${client_name} ${server_name} ${bonus_client_name}

re: fclean all

.PHONY: all bonus clean ${NAME}