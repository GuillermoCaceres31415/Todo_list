#include <iostream>
#include "Task.h"


int main() {

    std::string nometask="fareLaSpesa";

    std::string place="sicily";

    Task obj(nometask,place);

    Task obj1(nometask);

    std::cout<<obj1.getTaskName()<<" "<<obj1.getPlace()<<" "<<obj1.isCompleted();


    return 0;
}
