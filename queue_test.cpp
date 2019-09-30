#include <iostream>
#include "stock/queue.h"


int main(int argc, char const *argv[])
{
    // typedef int Item;
    Item x1 = 1;
    Item x2 = 20;
    Item x3 = 50;
    Queue q = Queue(5);  
    // error: Queue(5)先生成了一个临时的Queue对象, 再调用复制构造函数.而定义中复制构造函数为私有函数,因此会出现错误.
    // 正确的写法如下:
    // Queue q(10);
    q.enque(x1);  // 入队操作
    q.enque(x2);  // 入队操作
    q.enque(x3);  // 入队操作

    std::cout << "[1]The queue size: " << q.queue_count() << std::endl;

    q.deque(x1);  // 出队操作
    std::cout << "[2]The queue size: " << q.queue_count() << std::endl;

    // delete q;
    return 0;
}

