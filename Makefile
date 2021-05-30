client = client
server = server
client_bonus = client_bonus
NAME=fsd
all: ${NAME}

${NAME} :
	gcc client.c utils.c utils2.c -o client
	gcc server.c utils.c utils2.c -o server

bonus:
	gcc bonus/client_bonus.c utils.c utils2.c -o client_bonus
	gcc server.c utils.c utils2.c -o server

clean:

fclean: clean
	rm -rf ${client} ${server} ${client_bonus}

.PHONY: all bonus clean ${NAME}