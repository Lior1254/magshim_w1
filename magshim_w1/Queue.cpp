#include <iostream>  
#include "Queue.h"

int main() {

    return 0;
}

void enqueue(Queue* q, unsigned int newValue)
{
    /*
    * This function adds a new node the the end of the queue
    * input: get pointer to a queue, unsigned int
    * output: none
    */
    if (!isFull(q))
    {
        Queue* newNode = new Queue;
        newNode->queue_value = newValue;
        newNode->next = nullptr;

        if (isEmpty(q))
        {
            q->next = newNode;
            newNode->queue_index = 0;

        }
        else
        {
            unsigned int index = 0;
            Queue* temp = q;
            while (temp->next != nullptr)
            {
                temp = temp->next;
                index++;
            }
            temp->next = newNode;
            newNode->queue_index = index;
        }
    }
}

int dequeue(Queue* q)
{
    /*
    * This function delete the first node in the list and return the queue_value
    * input: get pointer to a queue
    * output: return the queue_value if the list empty return -1
    */
    if (isEmpty(q))
    {
        return -1;
    }
    else
    {
        unsigned int num = q->next->queue_value;
        Queue* temp = q->next;
        q->next = temp->next;

        delete(temp);
        return num;
    }
}


bool isFull(Queue* s)
{
    /*
    * This function return true if the list is full else retuern false
    * input: get pointer to a queue
    * output: boolean
    */

    unsigned int index = 0;
    Queue* temp = s;
    while (temp->next != nullptr)
    {
        temp = temp->next;
        index++;
    }
    return (index >= s->_maxSize);
}


bool isEmpty(Queue* s)
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

void initQueue(Queue* q, unsigned int maxSize)
{
    /*
    * This function rebooting node
    * input: get pointer to a queue,unsigned int
    * output: none
    */
    q->next = nullptr;
    q->_maxSize = maxSize;
    q->queue_value = 0;
    q->queue_index = 0;
}

void cleanQueue(Queue* q)
{
    /*
    * This function clean all the list
    * input: get pointer to a queue
    * output: none
    */
    Queue* temp = q;

    while (temp->next != nullptr)
    {
        temp = q->next;
        q->next = temp->next;
        delete(temp);
    }
}