#ifndef SERVER_H
# define SERVER_H

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

# define CLNT_MAX 10

void	error_handling(char	*message);

#endif
