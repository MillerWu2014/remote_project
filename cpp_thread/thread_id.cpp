#include <thread>
#include <iostream>


int main(int argc, char * args[]){
    std::thread::id master_thread;
    if (std::this_thread::get_id()==master_thread){
        std::cout << "This is master tread." << std::endl;
    }

    std::cout << "This is master tread: " << std::this_thread::get_id() << std::endl;
    return 0;
}