#include "chat.h"


void	error_handling(char	*message)
{
	fputs(message, stderr);
	fputs("\n", stderr);
	exit(1);
}
