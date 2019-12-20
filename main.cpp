#include <iostream>
#include "ThreadPool.h"
#include "Task.h"


void fill_queue(std::queue <Task *> * queue, const std::string& filename);


int main(int argc, char ** argv){
    //auto n_threads = (size_t) std::strtol(argv[1], nullptr, 10);
    std::string filename = argv[2];

    auto *queue = new std::queue <Task *>;
    fill_queue(queue, filename);

    auto n_threads = 6;
    ThreadPool pool(n_threads, queue);
}

void fill_queue(std::queue <Task *> * queue, const std::string& filename) {
    for (int i = 0; i < 10; i++)
        queue->emplace(new Task(nullptr, 0));
}
