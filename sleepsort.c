#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <stdint.h>

struct th {
    pthread_t thread;
    int data;
    int rc;
};

void* sleepPrint(void* data)
{
    struct th *self = (struct th *) data;
    printf("Created new thread with data = %d\n", self->data);
    pthread_detach(pthread_self());
    sleep(self->data);
    printf("%d\n", self->data);
    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    int a[argc - 1];
    int i;
    int rc;
    struct th thr;
    for(i = 1; i < argc; i++){
        a[i - 1] = strtol(argv[i], NULL, 10);
        thr.data = a[i - 1];
        rc = pthread_create(&thr.thread, NULL, sleepPrint, &thr);
    }
    if (rc)
    {
        printf("\n ERROR: return code from pthread_create is %d \n", rc);
        exit(1);
    }
    pthread_exit(NULL);
}
