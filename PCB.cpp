#include "PCB.h"

PCB::PCB(const int pid, const std::string& name, const int status, const int counter, const std::vector<int>& cpuReg){
    processID = pid;
    processName = name;
    switch (status){
    case 1 :                                        //определение статуса процесса в зависимости от принятого значения
        processStatus = Status::Running;
        break;
    case 2 :
        processStatus =  Status::Waiting;
        break;
    case 3 : 
        processStatus = Status::Stopped;
        break;
    }
    commandCounter = counter;
    cpuRegisters = cpuReg;
}



std::string PCB::takeStatus(){                          //возвращение соответствующего статуса в виде строки
    switch(processStatus) {
        case Status::Running : return "Running";
        case Status::Stopped : return "Stopped";
        case Status::Waiting : return "Waiting";
        default : return "Undef status";
    }
}