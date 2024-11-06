#include <iostream>
#include "Task.h"
#include "DateTime.h"


int main() {

    bool loop= true;
    while (loop) {

        std::cout << "----------------------------------------" << std::endl;
        std::cout << "        Benvenuto in To-do-list-app     " << std::endl;
        std::cout << "     [1]  per inserire una nuova task   " << std::endl;
        std::cout << "     [2]  visualizzare tute le tak      " << std::endl;
        std::cout << "     [3]            ESC                 " << std::endl;


        unsigned int command;
        std::cin >> command;


        switch (command) {
            case 1: {
                std::string nameTask, place;
                short unsigned int year, month, day, hour, minutes;

                std::cout << "Inserire il nome della task: ";
                std::cin >> nameTask;
                std::cout << std::endl;

                std::cout << "Inserire il luogo: ";
                std::cin >> place;
                std::cout << std::endl;

                std::cout << "Inserire anno: ";
                std::cin >> year;
                std::cout << std::endl;

                std::cout << "Inserire mese: ";
                std::cin >> month;
                std::cout << std::endl;

                std::cout << "Inserire giorno: ";
                std::cin >> day;
                std::cout << std::endl;

                std::cout << "Inserire ora: ";
                std::cin >> hour;
                std::cout << std::endl;

                std::cout << "Inserire minuti: ";
                std::cin >> minutes;
                std::cout << std::endl;

                DateTime dateTime(year, month, day, hour, minutes);
                Task task(nameTask, place, dateTime);

                std::ofstream file("AllTask.txt", std::ios::app);
                if (file.is_open()) {
                    file << nameTask << std::endl;
                    file.close();
                } else
                    std::cerr << "qualcosa è andato storto" << std::endl;
                break;


            }
            case 2: {
                std::ifstream file("AllTask.txt");
                if (file.is_open()) {
                    std::string task;
                    while (std::getline(file, task)) {
                        Task *newTask = Task::initializeFromFile(task);
                        newTask->printTask();
                    }
                }

                break;
            }
            case 3:
                loop= false;


        }
    }





    return 0;
}
