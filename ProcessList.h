#include "ListNode.h"

class ProcessList{
    ListNode* head;
public:
    ProcessList();              //конструктор
    ~ProcessList();             //деструктор

    bool insert(const PCB& new_PCB);                //метод вставки узла в список
    bool remove(int pid);                           //метод удаления узла из списка
    void printList();                               //метод вывода списка в консоль
};