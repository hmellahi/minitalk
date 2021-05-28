all:
	gcc client.c utils.c libft/libft.a -o client  -g -fsanitize=address 
	gcc server.c utils.c libft/libft.a -o server -g -fsanitize=address 