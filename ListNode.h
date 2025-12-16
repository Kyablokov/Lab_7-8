#ifndef LISTNODE_h
#define LISTNODE_h
#include "PCB.h"

class ListNode{
    PCB data;
    ListNode* next;
public:
    ListNode(const PCB& data, ListNode* next);              //конструктор
    ~ListNode();                                            //деструктор
    PCB getPCB() const;                                          //get-метод для просмотра процесса в узле
    ListNode* getNext() const;                              //get-метод для взятия указателя на следующий узел
    void setNext(ListNode* new_next);                       //set-метод для установки значения указателя на следующий узел
};

#endif