#ifndef CLIENT_H
# define CLIENT_H

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

void	error_handling(char	*message);

#endif
