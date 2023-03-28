#include "server.h"

int	g_clnt_socks[CLNT_MAX];
int	g_clnt_cnt = 0;

int main(int argc, char **argv)
{
	int					serv_sock;
	int					clnt_sock;
	int					clnt_addr_size;
	struct sockaddr_in	serv_addr;
	struct sockaddr_in	clnt_addr;

	serv_sock = socket(PF_INET, SOCK_STREAM, 0);
	if (serv_sock == -1)
		error_handling("socket errro");

	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY); //INADDR_ANY 현재 내 ip를 자동으로 가지고 온다
	serv_addr.sin_port=htons(7889);

	if (bind(serv_sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1)
		error_handling("bind error");

	if (listen(serv_sock, 5) == -1)
		error_handling("listen error");

	char	buff[200];
	int		recv_len = 0;
	while (true)
	{
		clnt_addr_size = sizeof(clnt_addr);
		clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_addr, &clnt_addr_size);

		//g_clnt_socks[g_clnt_cnt++] = clnt_sock;
		while(true)
		{
			recv_len = read(clnt_sock, buff, 200);
			printf("recv : ");
			for (int i = 0; i < recv_len; i++)
				printf("%02X", (unsigned char)buff[i]);
			printf("\n");
		}
	}
	return (0);
}
