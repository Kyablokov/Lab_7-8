#ifndef PCB_h
#define PCB_h
#include <string>
#include <vector>

using namespace std;


class PCB{
    int processID;
    string processName;
    enum processStatus {Running, Waiting, Stopped};
    int commandCounter;
    vector<int> cpuRegisters;
};



#endif