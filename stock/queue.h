#ifndef QUEUE_H_
#define QUEUE_H_

typedef int Item;

class Queue {
    struct Node {Item item; struct Node * next;};
    enum {Q_SIZE=10};

private:
    // defined the common variable
    Node * front;
    Node * rear;
    int items;
    const int qsize;
    Queue(const Queue & q): qsize(0){}
    Queue & operator=(const Queue & q){return *this;}

public:
    Queue(int qs = Q_SIZE);
    ~Queue();
    bool isempty() const;
    bool isfull() const;
    int queue_count() const;
    bool enque(const Item & item);
    bool deque(Item & item);
};

#endif