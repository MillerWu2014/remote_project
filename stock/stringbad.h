#include <iostream>

#ifndef STINGBAD_H_
#define STINGBAD_H_

class StringBad{
private:
    char * str;
    int len;
    static int num_strings;

public:
    StringBad(const char *);
    StringBad();
    StringBad(const StringBad & st);
    ~StringBad();
    StringBad & operator=(const StringBad & st);
    friend std::ostream & operator <<(std::ostream & os, const StringBad & st);
};

#endif