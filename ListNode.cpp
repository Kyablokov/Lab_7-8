#include "ListNode.h"

ListNode::ListNode (const PCB& data, ListNode* next)
    :data(data), next(next)
{

}

ListNode::~ListNode() = default;                    //деструктор умолчания

PCB ListNode::getPCB() const {return data;}
ListNode* ListNode::getNext() const {return next;}
void ListNode::setNext(ListNode* new_next) {next = new_next;}

