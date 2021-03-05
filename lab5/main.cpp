#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <string.h>
#include "thread_writer.h"


#define MAX_THREADS 100

int main (int argc, char**argv) {
    pthread_t threads[MAX_THREADS];
    struct thread_data td[MAX_THREADS];
    int rc, i = 0;
    char* filename = argv[1];
    printf("%s\n", filename);
    std::fstream output(filename, std::ios::out | std::ios::app);
    
    std::string choice = "qwe";

    while(strcmp(choice.c_str(), "q") != 0) {
        printf("q - exit\nw - add thread\ne - delete last thread\n");
        std::cin >> choice;
        if (strcmp(choice.c_str(), "w") == 0) {
            std::cout << "main() : creating thread, " << i << std::endl;
            td[i].thread_id = i;
            td[i].message = argv[i+2];
            td[i].output = &output;
            rc = pthread_create(&threads[i], NULL, thread_function, (void *)&td[i]);
            i++;
            if (rc) {
                std::cout << "Error:unable to create thread," << rc << std::endl;
                exit(-1);
            }
        } else if (strcmp(choice.c_str(), "e") == 0) {
            rc = pthread_cancel(threads[i-1]);
            if (rc) {
                std::cout << "Error:unable to cancel thread," << rc << std::endl;
                exit(-1);
            }
            i--;
        }
    }
    pthread_exit(NULL);
}

// gcc -g main.cpp -o main -lstdc++ -lpthread && ./main output.txt privet kak dela Jenya
// make clean && make all && ./parallel-writer output.txt qwer reqw reqw reqw