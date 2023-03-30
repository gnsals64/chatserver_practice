#include "client.h"

#define BUFFER_SIZE 100
#define NAMESIZE 20

// int	StoHEX(char fi, char sc);
// void	*send_message(char *arg);
// void	*recv_message(char *arg);

char message[BUFFER_SIZE];

void	*rcv(void *arg)
{
	printf("rcv thread created\n");
	int		sock = (int)arg;
	char	buff[500];
	int		len;

	while (true)
	{
		len = read(sock, buff, sizeof(buff));
		if (len == -1)
		{
			printf("sock close\n");
			break;
		}
		printf("%s", buff);

	}
	pthread_exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	int					sock;
	struct sockaddr_in serv_addr;
	pthread_t			rcv_thread;

	char	id[100];

	if (argc < 2)
	{
		printf("you have to enter Id\n");
		return (0);
	}

	strcpy(id, argv[1]);
	printf("id : %s\n", id);
	sock = socket(PF_INET, SOCK_STREAM, 0);
	if (sock == -1)
		error_handling("socket errro");

	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	serv_addr.sin_port=htons(7889);

	if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1)
		error_handling("connect error");

	pthread_create(&rcv_thread, NULL, rcv, (void*)sock);
	char chat[100];
	char msg[1000];


	while (true)
	{
		printf("채팅 입력 : ");
		gets(chat);
		sprintf(msg, "[%s] : %s\n", id, chat);
		printf("send : %s\n", msg);
		write(sock, msg, strlen(msg) + 1);
		sleep(1);
	}
	close(sock);
	return (0);
}
