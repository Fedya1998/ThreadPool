#include <iostream>
#include "ThreadPool.h"

void fill_queue(std::queue <Task> & queue, const std::string& filename);


int main(int argc, char ** argv){
    auto n_threads = (size_t) std::strtol(argv[1], nullptr, 10);
    std::string filename = argv[2];

    std::queue <Task> queue;
    fill_queue(queue, filename);

    ThreadPool pool(n_threads);
    pool.Work(queue);
}

void fill_queue(std::queue <Task> & queue, const std::string& filename) {

}
