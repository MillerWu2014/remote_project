#include <iostream>

class Person
{
public:
    Person(const char *name, float weight, float height){
        name_ = name;
        weight_ = weight;
        height_ = height;
    }

    void show(){
        std::cout << "The person name:" << name_ << ".\n";
    }

    ~Person(){
        std::cout << "Delete all of person's attrubutes. Bye!" << std::endl;
    }
    
private:
    const char *name_;
    float weight_;
    float height_;
};


int main(int argc, char const *argv[])
{
    Person miller = Person("Miller", 118.5, 168.0);
    miller.show();
    return 0;
}
