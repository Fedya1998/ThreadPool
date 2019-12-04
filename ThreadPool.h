//
// Created by Fedya on 2019-12-04.
//

#ifndef THREADPOOL_THREADPOOL_H
#define THREADPOOL_THREADPOOL_H

#include <cstdlib>
#include <thread>
#include <vector>
#include <queue>
#include <mutex>

class Task {
    uint64_t* ptr_;
    size_t size_;

public:
    void Do();
};

class ThreadPool {
    std::mutex queue_mutex_;
    std::mutex thread_number_mutex_;
    std::mutex * mutexes_;

    const size_t size_;
    size_t free_threads_;
    std::queue <Task> queue_;
    std::vector <std::thread> threads_;

public:
    explicit ThreadPool(size_t size);
    ~ThreadPool() = default;

    void Work(std::queue <Task>& queue);
};



#endif //THREADPOOL_THREADPOOL_H
