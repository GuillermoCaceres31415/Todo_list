//
// Created by Guillermo on 05/11/24.
//

#include "Task.h"

Task::Task(std::string &n, std::string &pl,DateTime &dt,bool com):taskName(n),place(pl), dateTime(dt),completed(com){
    std::ofstream file(taskName+".txt");
    if (file.is_open()){
        file<<place<<std::endl;

        file<<dateTime.getYear()<<std::endl;
        file<<dateTime.getMonth()<<std::endl;
        file<<dateTime.getDay()<<std::endl;
        file<<dateTime.getHour()<<std::endl;
        file<<dateTime.getMinutes()<<std::endl;

        file<<completed<<std::endl;


        file.close();
    } else
        std::cerr<<"qualcosa è andato storto"<<std::endl;
}


Task *Task::initializeFromFile(std::string &n) {

    std::ifstream file (n+".txt");
    if (file.is_open()){

        std::string place;
        std::getline(file, place);

        short unsigned int year, month, day, hour, minutes;
        file>>year;
        file>>month;
        file>>day;
        file>>hour;
        file>>minutes;

        bool compelte;
        file>>compelte;

        file.close();

        DateTime dt(year,month,day,hour,minutes);


        Task *obj=new Task(n,place,dt,compelte);
        return obj;
    } else{
        std::cout<<"il nome non corrisponde";
        return nullptr;
    }
}

void Task::printTask() {
    std::cout<<taskName<<" "<<place<<" "<<dateTime.getYear()<<" "<<completed;
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


