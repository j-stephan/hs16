#include <pthread.h>
#include <iostream>

#include <unistd.h>

using namespace std;

pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;

void* f1(void *p) {
    pthread_mutex_lock(&m);
    usleep(20 * 1000);
    pthread_mutex_unlock(&m);
    return NULL;
}

void* f2(void *p) {
    usleep(10 * 1000);
    pthread_mutex_lock(&m);
    usleep(20 * 1000);
    pthread_mutex_unlock(&m);
    return NULL;
}

int main(int argc, char **args) {

    pthread_t threads[2];

    pthread_create(&threads[0], NULL, f1, 0);
    pthread_create(&threads[1], NULL, f2, 0);

    /* wait for the second thread to finish */
    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);

    pthread_mutex_destroy(&m);

    return 0;
}
