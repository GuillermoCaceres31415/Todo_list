#include <iostream>
#include "Task.h"
#include "DateTime.h"


int main() {

    std::string nometask="fare";

    std::string place="lucca";

    DateTime dt(2024, 2, 29, 14, 30);


    Task *objP=new Task(nometask,place,dt);




    Task *obj=Task::initializeFromFile(nometask);

    obj->printTask();



    return 0;
}
