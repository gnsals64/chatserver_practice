#include "client.h"

#define BUFFER_SIZE 100
#define NAMESIZE 20

// int	StoHEX(char fi, char sc);
// void	*send_message(char *arg);
// void	*recv_message(char *arg);

char message[BUFFER_SIZE];

int	main(int argc, char **argv)
{
	int					sock;
	struct sockaddr_in serv_addr;

	sock = socket(PF_INET, SOCK_STREAM, 0);
	if (sock == -1)
		error_handling("socket errro");

	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	serv_addr.sin_port=htons(7889);

	if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1)
		error_handling("connect error");

	unsigned char msg[100] = {0x01,2,3,4,5,6,1,2,3,4,2,1,2,3,0x0c};

	while (true)
	{
		printf("send : \n");
		write(sock, msg, 15);
		sleep(1);
	}
	close(sock);
	return (0);
}
