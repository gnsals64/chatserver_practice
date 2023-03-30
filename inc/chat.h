#ifndef CHAT_H
# define CHAT_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/socket.h>
# include <arpa/inet.h>
# include <sys/types.h>
# include <netinet/in.h>
# include <pthread.h>
# include <stdbool.h>

# define BUFFER_SIZE 200
# define CLNT_MAX 10

void	error_handling(char	*message);

#endif
