//
// Created by Fedya on 2019-12-05.
//

#ifndef THREADPOOL_TASK_H
#define THREADPOOL_TASK_H

#include <cstdlib>

// OLD

class Task {
    uint64_t* ptr_;
    size_t size_;
    uint64_t block_;
    uint64_t general_ptr_;
    bool done;

public:
    Task() = default;
    Task (uint64_t *ptr, size_t size): ptr_(ptr), size_(size) {};
    void Do();
    bool Die();
};


#endif //THREADPOOL_TASK_H
