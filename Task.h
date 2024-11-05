//
// Created by Guillermo on 05/11/24.
//

#ifndef TODO_LIST_TASK_H
#define TODO_LIST_TASK_H
#include "iostream"
#include <fstream>
#include "DateTime.h"

class Task {
private:
    std::string taskName;
    std::string place;
    DateTime dateTime;
    bool completed;

public:
    Task(std::string &n,std::string &pl,DateTime &dateTime,bool com = false);

    static Task * initializeFromFile(std::string &n);

    void printTask();




    const std::string &getTaskName() const;

    const std::string &getPlace() const;

    bool isCompleted() const;

};


#endif //TODO_LIST_TASK_H
