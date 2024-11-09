#include <iostream>  
#include "LinkedList.h"

int main() {

    return 0;
}

void eStack(Stack* s, unsigned int newValue)
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
        newNode->next = nullptr;

        if (isEmpty(s))
        {
            s->next = newNode;

        }
        else
        {
            unsigned int index = 0;
            Stack* temp = s;
            newNode->next = temp;
            s -> next = newNode;
        }
    }
}

void dStack(Stack* s)
{
    /*
    * This function delete the first node in the Stack 
    * input: get pointer to a Stack
    * output: none
    */
    if (isEmpty(s))
    {
        std::cout << "Stac is Empty!" << std::endl;
    }
    else
    {

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







