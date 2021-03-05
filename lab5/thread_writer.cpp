#ifndef THREAD_WRITER_CPP
#define THREAD_WRITER_CPP
#include "thread_writer.h"

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t address_lock = PTHREAD_MUTEX_INITIALIZER;

void *thread_function(void *threadarg) {
    struct thread_data *my_data;
    while(1) {
        my_data = (struct thread_data *) threadarg;
        std::cout << "Thread ID : " << my_data->thread_id ;
        std::cout << " Message : " << my_data->message << std::endl;
        pthread_mutex_lock(&lock);
        *my_data->output << std::string(my_data->message) << std::endl;
        pthread_mutex_unlock(&lock);
        sleep(1);
    }
}
#endif /* THREAD_WRITER_CPP */