#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

void* doSomeThing(void* arg) {
    unsigned long i = 0;
    pthread_t id = pthread_self();

    if (pthread_equal(id, tid[0])) {
        printf("First thread processing\n");
    } else {
        printf("Second thread processing\n");
    }

    for (i = 0; i < (0xFFFFFFFF); i++);

    return NULL;
}

int main(void) {
    int i = 0;
    int err;

    while (i < 2) {
        err = pthread_create(&(tid[i]), NULL, &doSomeThing, NULL);

        if (err != 0) {
            printf("Can't create thread: [%s]\n", strerror(err));
        } else {
            printf("Thread created successfully\n");
        }

        i++;
    }

    // Allowing threads to complete before the program exits
    sleep(5);

    return 0;
}
