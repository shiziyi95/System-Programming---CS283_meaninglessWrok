#include "csapp.h"

void *thread(void *vargp);

int main()
{
	pthread_t tid;
	//long take argument in runtime

	//create to neate new thread
	pthread_create(&tid,NULL,thread,NULL);
		//join terminate the thread
	pthread_joi n(tid,NULL);

}

void *thread(void *vargp)
{
	sleep(1);
	printf("hello,word\n");
	return NULL;
}