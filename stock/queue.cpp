#include <cstdlib>
#include "queue.h"

Queue::Queue(int qs) : qsize(qs), items(0), front(NULL), rear(NULL) {}

Queue::~Queue(){
    Node * temp;
    while (front != NULL){
        temp = front;
        front = front->next;
        delete temp;
    }
}

bool Queue::isempty() const {
    return items == 0;
}

bool Queue::isfull() const {
    return items == qsize;
}

int Queue::queue_count() const {
    return items;
}

bool Queue::enque(const Item & item){
    if (isfull()){
        return false;
    }
    Node * add = new Node;
    add->item = item;
    add->next = NULL;
    items++;
    if (front==NULL){
        front = add;
    } else {
        rear->next = add;
    }
    rear = add;
    return true;
}

bool Queue::deque(Item & item){
    if (front == NULL){
        return false;
    }
    item = front->item;
    items--;
    Node * temp = front;
    front = front->next;
    delete temp;
    if (items == 0){
        rear = NULL;
    }
    return true;
}