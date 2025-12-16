#include "ProcessList.h"
#include <iostream>
#include <limits>

std::string input(const std::string& line){                                                     //ввод строки с проверкой и очисткой
    std::string input;                                                                          //буфера
    std::cin.clear();
    while (true){
        std::cout << line;
        std::cin.clear();
        getline(std::cin,input);
        if (input.empty()){
            std::cout << "Строка не может быть пустой. Попробуйте ещё раз." << std::endl;
            continue;
        }
        break;
    }
    return input;
}


int intinput(const std::string& line, bool status = false){                                     //ввод целого числа и очистка буфера
    int input;
    std::cin.clear();

    while (true){
        std::cout << line;
        if (!(std::cin >> input)){
            std::cin.clear();
            std::cout << "Введите число. Попробуйте ещё раз" << std::endl;
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');                     //для очистки буфера после ввода числа

        if (input < 0){                
            std::cout << "Идентификатор должен быть больше 0, попробуйте ещё раз" << std::endl;
            continue;
        }

        if (status && (input>3)){                                                               //проверка на соответствие условию ввода статуса
            std::cout << "Введите одно их трёх значений (1 - Running; 2 - Waiting; 3 - Stopped)" << std::endl;
            continue;
        }

        std::cin.clear();
        break;

    }
    std::cin.clear();
    return input;
}


void insertmain(ProcessList& ProcessList){
    std::cout << std::endl << "Сколько процессов вы бы хотели добавить?" << std::endl;
    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++){

        std::cout << std::endl;

        int pid = intinput("Process ID: ");

        std::string name = input("Process name: ");
        
        int status = intinput("Process status (1 - Running; 2 - Waiting; 3 - Stopped): ", true);  

        int commandCounter = intinput("Следующая исполняемая команда (Command counter): ");

        int how_much = intinput("Сколько регистров вы хотите записать? ");

        std::vector<int> cpuReg = {};
        int reg;
                                                                                            //ввод регисторов процессора и вставка их в вектор
        for (int i = 0; i < how_much; i++){
            std::cin >> reg;
            cpuReg.push_back(reg);
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        PCB new_pcb = PCB(pid,name,status, commandCounter, cpuReg);
        if (ProcessList.insert(new_pcb)){
            std::cout << "Узел добавлен!" << std::endl;
        }

    }

}

void removemain(ProcessList& ProcessList){
    std::cout << std::endl << "Сколько процессов вы бы хотели удалить?" << std::endl;
    int n;
    std::cin >> n;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    int choice;
    for (int i = 0; i <  n; i++){
        std::cout << "Введите Process ID процесса, который вы хотите удалить: ";
        std::cin >> choice;
        ProcessList.remove(choice);
    }
}

int main(){
    ProcessList ProcessList;
    
    insertmain(ProcessList);

    ProcessList.printList();

    removemain(ProcessList);

    ProcessList.printList();


    std::cout << std::endl <<"Попытаемся ввести неправильные данные" << std::endl;

    insertmain(ProcessList);

    removemain(ProcessList);

    ProcessList.printList();

}