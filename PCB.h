#ifndef PCB_h
#define PCB_h
#include <string>
#include <vector>

struct PCB{                                                 
    int processID;              
    std::string processName;

    enum class Status {Running = 1, Waiting = 2, Stopped = 3};
    Status processStatus;

    int commandCounter;
    std::vector<int> cpuRegisters;


    PCB(const int pid, const std::string& name, const int status, const int counter, const std::vector<int>& cpuReg);       //конструктор
    std::string takeStatus();               //метод для взятия статуса
};


#endif