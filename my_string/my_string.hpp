#ifndef MY_STRING
#define MY_STRING
#include <iostream>
#include <cstring>
#include <cassert>
namespace my_string{


size_t strlen(const char *str);


class MyString{

public:
    MyString(const char *str = nullptr);
    MyString(const MyString& other);
    MyString& operator=(const MyString &other);

    ~MyString();


private:
    char *ch = nullptr;
};


}



#endif