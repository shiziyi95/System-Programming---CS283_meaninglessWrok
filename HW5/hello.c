#include "csapp.h"
void *thread(void *vargp);

int main(int argc, char *argv[])
{
	pthread_t tid;
	//long take argument in runtime
	int num = atoi(argv[1]);
	int i;
	for (i = 0; i < num; i++)//for loop to do things n times, where n is passed in
	{
		//create to neate new thread
		pthread_create(&tid,NULL,thread,NULL);
		//join terminate the thread
		pthread_join(tid,NULL);
	}
	exit(0);
}

void *thread(void *vargp)
{
	printf("hello,word\n");
	return NULL;
}