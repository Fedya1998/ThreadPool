//
// Created by Fedya on 2019-12-04.
//

#include "ThreadPool.h"

ThreadPool::ThreadPool(size_t size):size_(size), free_threads_(size), mutexes_(new std::mutex[size]) {
    for (int i = 0; i < size_; i++){
        threads_[i] = std::thread (&ThreadPool::Work, std::ref(queue_));
    }
}

void ThreadPool::Work(std::queue <Task> & queue) {
    for (;;) {

        queue_mutex_.lock();
        thread_number_mutex_.lock();
        if (queue.empty())
            if (free_threads_ == size_)
                return;
        free_threads_--;
        thread_number_mutex_.unlock();

        auto task = queue.front();
        queue.pop();
        queue_mutex_.unlock();


        task.Do();

        if (check_second()) {
            create_new_task();
        }

        thread_number_mutex_.lock();
        free_threads_++;
        thread_number_mutex_.unlock();
    }
}

