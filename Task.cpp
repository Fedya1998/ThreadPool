//
// Created by Fedya on 2019-12-05.
//

#include <thread>
#include <iostream>
#include "Task.h"

void Task::Do() {
    std::thread::id this_id = std::this_thread::get_id();

    std::cout << "thread " << this_id << "\n";
}

bool Task::Die() {
    return done;
}
