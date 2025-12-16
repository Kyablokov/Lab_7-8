#include "ProcessList.h"
#include <iostream>
#include <limits>


ProcessList::ProcessList()
    : head(nullptr)
{

}

ProcessList::~ProcessList(){                                                    //удаляем каждый узел
    ListNode* real_node =  head;

    while (real_node != nullptr) {
        ListNode* copy = real_node;
        real_node = real_node->getNext();
        delete copy;
    }
}




bool ProcessList::insert(const PCB& new_PCB){


    if (head == nullptr || head->getPCB().processID > new_PCB.processID){       //если узлов вообще нет или id первого меньше нового,
        head = new ListNode(new_PCB, head);                                     //то вставляем новый узел на первое место
        return true;
    }

    ListNode* real_node = head;


    while (true){                                                               //проверка на единственность pid
        if (real_node->getPCB().processID == new_PCB.processID){
            std::cout << "Процесс с таким Process ID уже существует. Данные не добавлены" << std::endl; 
            return false;
        }

        if (real_node->getNext() == nullptr){
            break;
        }

        real_node = real_node->getNext();

    }

    ListNode* new_node = new ListNode(new_PCB, nullptr);
    ListNode* old_node = head;


    if (head->getNext() == nullptr){                                            //если существует только первый узел и его id меньше
        head->setNext(new_node);                                                //id нового узла, то ставим новый узел вторым
        return true;
    }

    real_node = head->getNext();

    while(true){                                                                //вставляем по надобности новый узел между двумя старыми 

        if (new_PCB.processID < real_node->getPCB().processID){                 //и меняем всем поля "next"
            old_node->setNext(new_node);
            new_node->setNext(real_node);
            return true;
        }

        if (real_node->getNext() == nullptr){                                   //если дошли до конца, то вставляем новый узел в конец
            real_node->setNext(new_node);
            return true;
        }

        old_node = real_node;
        real_node = real_node->getNext();
    }

}

bool ProcessList::remove(int pid){

    if (head == nullptr){                                                       //если узлов нет, то и удалять нечего
        std::cout << "Нечего удалять" << std::endl;
        return false;
    }

    ListNode* real_node = head;

    while (true){                                                               //проверка на существование pid

        if (real_node->getPCB().processID == pid){
            break;
        }

        if (real_node->getNext() == nullptr){
            std::cout << "Процесс с таким Process ID не найден" << std::endl;
            return false;            
        }

        real_node = real_node->getNext();
    }


    if (head->getPCB().processID == pid){

        if (head->getNext() != nullptr){                                        //если нужно удалить первый, но Не последний узел,
            ListNode* copy = head;                                              //то второй узел становится первым, а первый удаляется
            head = head->getNext();
            delete copy;

        }
        else{
            ListNode* copy = head;                                              //если нужно удалить первый и последний узел - 
            head = nullptr;                                                     //просто удаляем
            delete copy;
        }

        std::cout << "Узел удалён" << std::endl;
        return true;
    }

    ListNode* old_node = head;
    real_node = head->getNext();

    while(true){                                                                //аналогично с insert удаляем в середине или конце
        if(real_node->getPCB().processID == pid){
            if(real_node->getNext() != nullptr){
                old_node->setNext(real_node->getNext());
                delete real_node;
                std::cout << "Узел удалён" << std::endl;
                return true;
            }
            else{
                old_node->setNext(nullptr);
                delete real_node;
                std::cout << "Узел удалён" << std::endl;
                return true;
            }
        
        }
        old_node = real_node;
        real_node = real_node->getNext();
    }
}

void ProcessList::printList(){
    std::cout << std::endl;
    if (head == nullptr){
        std::cout << "Нечего выводить" << std::endl;
        return;
    }
    ListNode* real_node = head;
    while(true){
        std::cout << "Process ID: " << real_node->getPCB().processID << std::endl;
        std::cout << "Process name: " << real_node->getPCB().processName << std::endl;
        std::cout << "Process status: " << real_node->getPCB().takeStatus() << std::endl;
        std::cout << "Commands: ";
        for (int command : real_node->getPCB().cpuRegisters){                   //вывод из вектора
            std::cout << command << " ";
        }
        std::cout << std::endl << "---------------------------"<<std::endl;

        if (real_node->getNext() != nullptr){                                   //идём дальше, если узел не последний
            real_node = real_node->getNext();
            continue;
        }
        else{
            break;
        }
    }
    return;
}