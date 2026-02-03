#include <iostream>
#include <cassert>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;


int my_strlen(const char *str){  // input string`s address
    if(str == nullptr)
        return 0;
        
    const char *ptr = str;      // 常量指针，指向的内存不能被修改
    while(*ptr != '\0')
        ptr++;
    return ptr - str;
}


void* my_memcopy(char *des, char *src, size_t size){
    char *ptr_d = des;
    char *ptr_s = src;
    while(size > 0){
        *ptr_d++ = *ptr_s++;
        size--;
    }
    return des;
}


void my_memset(char *des, char value, size_t size){
    char *ptr = des;
    while(size > 0){
        *ptr++ = value;
        size--;
    }
}


#define my_offestof(type, member) (size_t) ( &( ((type*) 0)->member) )
typedef struct {
    char  a;      // 0
    int   b;      // 4 (通常有3字节填充)
    short c;      // 8
    char  d;      // 10
} MyStruct;

int main(){
    char src[] = "hello world";
    char des[20] = {0};
    my_memcopy(des, src, my_strlen(src) + 1);
    printf("Test 1: src=%s, des=%s\n", src, des);

    size_t offest = my_offestof(MyStruct, d);
    printf("Test 2: offest of b is %llu\n", offest);

    return 0;
}