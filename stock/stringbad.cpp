#include <iostream>
#include <cstring>
#include "stringbad.h"

using std::cout;

// initializing static class member 
int StringBad::num_strings = 0;

// class methods
StringBad::StringBad(const char * s){
    len = std::strlen(s);
    str = new char[len+1];
    std::strcpy(str, s);
    num_strings++;
    cout << num_strings << ": \"" << str << "\" object created!";
} 

StringBad::StringBad(){
    len = 4;
    str = new char[4];
    std::strcpy(str, "c++");
    num_strings++;
    cout << num_strings << ": \"" << str << "\" object created!";
}

StringBad::StringBad(const StringBad & st){
    num_strings++;
    len = st.len;
    str = new char[len+1];
    strcpy(str, st.str);
    cout << "number strings" << ": \"" << str << "\" object created\n" << std::endl;
}

StringBad::~StringBad(){
    cout << "\"" << str << "\" object deleted!, ";
    --num_strings;
    cout << num_strings << " left\n";
    delete [] str;
}

StringBad & StringBad::operator=(const StringBad & st){
    if(this == &st){
        return *this;
    }
    delete [] str;
    len = st.len;
    str = new char[len+1];
    strcpy(str, st.str);
    return *this;
}

std::ostream & operator<<(std::ostream & os, const StringBad & st){
    os << st.str;
    return os;
}