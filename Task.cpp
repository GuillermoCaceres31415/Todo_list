//
// Created by Guillermo on 05/11/24.
//

#include "Task.h"

Task::Task(std::string &n, std::string &pl):taskName(n),place(pl),completed(false){
    std::ofstream file(taskName+".txt");
    if (file.is_open()){
        file<<place<<std::endl;
        file<<completed<<std::endl;
        file.close();
    } else
        std::cerr<<"qualcosa è andato storto"<<std::endl;
}

 Task::Task(std::string &n):taskName(n) {
    std::ifstream file (taskName+".txt");
    if (file.is_open()){
        //fix up
        std::string dato;
        std::getline(file, dato);
        this->place=dato;
        file>>completed;

        file.close();
    }

}

const std::string &Task::getTaskName() const {
    return taskName;
}

const std::string &Task::getPlace() const {
    return place;
}

bool Task::isCompleted() const {
    return completed;
}


