#include "chat.h"

int	g_clnt_socks[CLNT_MAX];
int	g_clnt_cnt = 0;

void	send_All_clnt(char *msg, int my_sock)
{
	for (int i = 0 ; i < g_clnt_cnt; i++)
	{
		if (g_clnt_socks[i] != my_sock)
			write(g_clnt_socks[i], msg, strlen(msg) + 1);
	}
}

void	*clnt_connection(void *arg)
{
	int		clnt_sock = (int)arg;
	int		str_len = 0;
	char	msg[BUFFER_SIZE];

	while(true)
	{
		str_len = read(clnt_sock, msg, sizeof(msg));
		if (str_len == 0)
			break ;
		printf("%s", msg);
		send_All_clnt(msg, str_len);
	}
	close(clnt_sock);
	pthread_exit(0);
	return (NULL);
}

int main(int argc, char **argv)
{
	int					serv_sock;
	int					clnt_sock;
	int					clnt_addr_size;

	pthread_t			t_thread;
	struct sockaddr_in	serv_addr;
	struct sockaddr_in	clnt_addr;

	serv_sock = socket(PF_INET, SOCK_STREAM, 0);
	int option = 1;

	setsockopt(serv_sock, SOL_SOCKET, SO_REUSEADDR, &option, sizeof(option));
	if (serv_sock == -1)
		error_handling("socket errro");

	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY); //INADDR_ANY 현재 내 ip를 자동으로 가지고 온다
	serv_addr.sin_port=htons(7998);

	if (bind(serv_sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1)
		error_handling("bind error");

	if (listen(serv_sock, 5) == -1)
		error_handling("listen error");

	char	buff[200];
	int		recv_len = 0;
	char	id[200];

	while (true)
	{
		clnt_addr_size = sizeof(clnt_addr);
		clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_addr, &clnt_addr_size);
		read(clnt_sock, id, sizeof(id));
		g_clnt_socks[g_clnt_cnt++] = clnt_sock;
		pthread_create(&t_thread, NULL, clnt_connection, (void *)clnt_sock);
		printf("Connected %s\n", id);
	}
	return (0);
}
