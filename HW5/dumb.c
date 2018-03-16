   #include <pthread.h>
   //including some libraries.
   #include <stdio.h>
   #include <stdlib.h>
   
   //create a structure to pass the value through pthread_create()
   struct arguments
   {
   	int *sum;
   	int *id;
   };
	   
   
   #define NUM_THREADS 8
   char *messages[NUM_THREADS];
   void *PrintHello(void *threadarg)
    {
     int taskid, sum;
     char *hello_msg;
     /* ... */
     struct arguments *argument;
     argument = (struct arguments *) threadarg;
     
     taskid = *(argument->id);//
     sum  = *(argument->sum);//
     hello_msg = messages[taskid];//
     /* ... */
     printf("Thread %d %s Sum=%d\n", taskid, hello_msg, sum);
     pthread_exit(NULL);
    }
   int main(int argc, char *argv[])
    {
     pthread_t threads[NUM_THREADS];
     int rc, t, sum;
     sum=0;
     struct arguments *arg;
     arg = (struct arguments *) calloc(1, sizeof(struct arguments));
     
     messages[0] = "Hello-0";
     messages[1] = "Hello-1";
     messages[2] = "Hello-2";
     messages[3] = "Hello-3";
     messages[4] = "Hello-4";
     messages[5] = "Hello-5";
     messages[6] = "Hello-6";
     messages[7] = "Hello-7";
     arg->sum = &sum;//
     arg->id = &t;//
     for(t = 0; t < NUM_THREADS; t++)
      {
       sum = sum + t;
       pthread_create(&threads[t], NULL, PrintHello, (void *)arg);
       pthread_join(threads[t], NULL);
       
       /* ... */
       
       
       
       printf("Creating thread %d\n", t);
       /* ... */
      }
     pthread_exit(NULL);
    }