#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int a = 0;

void	*thread1(void *arg)
{
	printf("arg : %d\n", (int)arg);
	while (1)
	{
		printf("thread%d : a[%d]\n", (int)arg, ++a);
		sleep(2);
	}
	return (NULL);
}

int main()
{
	pthread_t s_thread[2];
	int	id1 = 77;
	int	id2 = 88;

	pthread_create(&s_thread[0], NULL, thread1, (void *)id1);
	pthread_create(&s_thread[1], NULL, thread1, (void *)id2);

	pthread_join(s_thread[0], NULL);
	pthread_join(s_thread[1], NULL);
}
