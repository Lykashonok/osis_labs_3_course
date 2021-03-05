#ifndef THREAD_WRITER_H
#define THREAD_WRITER_H
#include <unistd.h>
#include <iostream>
#include <fstream>

void *thread_function(void *threadarg);

struct thread_data {
    int  thread_id;
    char *message;
    std::fstream *output;
};
#endif /* THREAD_WRITER_H */