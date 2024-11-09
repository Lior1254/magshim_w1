#include <iostream>  
#include "Stack.h"

int main() {

    return 0;
}

void push(Stack* s, unsigned int newValue)
{
    /*
    * This function adds a new node tp the begining of the stack
    * input: get pointer to a stack,unsigned int
    * output: none
    */
    if (!isFull(s))
    {
        Stack* newNode = new Stack; 
        newNode->stack_value = newValue;
        
        newNode->next = s->next; 
        s->next = newNode;   
    }
    else
    {
        std::cout << "Stac is Full!" << std::endl;
    }
}

int pop(Stack* s)
{
    /*
    * This function delete the first node in the Stack
    * input: get pointer to a Stack
    * output: none
    */
    if (isEmpty(s))
    {
        std::cout << "Stac is Empty!" << std::endl;
        return -1;
    }
    else
    {
        unsigned int value = s->next->stack_value;
        Stack* temp = s->next;
        s->next = temp->next;

        delete(temp);
    }
}


bool isFull(Stack* s)
{
    /*
    * This function return true if the list is full else retuern false
    * input: get pointer to a Stack
    * output: boolean
    */

    unsigned int index = 0;
    Stack* temp = s;
    while (temp->next != nullptr)
    {
        temp = temp->next;
        index++;
    }
    return (index >= s->_maxSize);
}


bool isEmpty(Stack* s)
{
    /*
    * This function return return true if the list is empty else retuern false
    * input: get pointer to a queue, unsigned int
    * output: boolean
    */

    if (s->next == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void initStack(Stack* s)
{
    /*
    * This function rebooting the value of the node
    * input: get pointer to a queue
    * output: none
    */
    s->next = nullptr;
    s->stack_value = 0;
    s->_maxSize = 100;
}

void cleanStack(Stack* s)
{
    /*
    * This function delete all the nodes in the stack
    * input: get pointer to a queue
    * output: none
    */
    while (!isEmpty(s))
    {
        pop(s);
    }
}







