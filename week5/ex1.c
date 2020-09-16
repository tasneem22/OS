#include <pthread.h>                                                                                                    #include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define Number_threads 4

int i;

void* PrintHello(void* arg)
{
    printf("Hallo from thread %lu\n",*(unsigned long*)arg );
    pthread_exit(NULL);
}


void task1(){

    // Create a new thread that will execute 'PrintHello’
        /*
         * Order of printing is not defined.
         * Main thread can sometimes print first,
         * and other times the new thread would print first                                                                      */

    for (i = 0; i < Number_threads; i++){
     pthread_t thread_id;
     pthread_create(&thread_id, NULL, PrintHello, &thread_id);
     printf("\n I am thread %lu. Created new thread (%lu) :P ...\n", pthread_self(),  thread_id);

    }

    return ;
}

void task2(){

    /*
     * Will wait until the thread exits to create the new one.
     * The ID printed is the same for all of them, because the previous one exited and the ID had been reused
     */

    for(i = 0;i < Number_threads;++i){
        pthread_t thread_id;
                pthread_create(&thread_id, NULL, PrintHello, &thread_id);

        printf("\n I am thread %lu. Created new thread (%lu) :P ...\n", pthread_self(), thread_id);

                pthread_join(thread_id, NULL);
        /*
         * The pthread_join() function suspends execution of the calling thread until the target thread terminates
         * , unless the target thread has already terminated.
         */

    }

    pthread_exit(NULL);

    return;

}
int main(int argc, char * argv[]){

    task1();
    printf("\n\n second task\n\n");
    task2();
}
