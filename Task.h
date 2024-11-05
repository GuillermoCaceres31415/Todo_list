//
// Created by Guillermo on 05/11/24.
//

#ifndef TODO_LIST_TASK_H
#define TODO_LIST_TASK_H
#include "iostream"
#include <fstream>

class Task {
private:
    std::string taskName;
    std::string place;
    bool completed;
public:
    Task(std::string &n,std::string &pl);

    explicit Task(std::string &n);


    const std::string &getTaskName() const;

    const std::string &getPlace() const;

    bool isCompleted() const;

};


#endif //TODO_LIST_TASK_H
