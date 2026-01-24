#include <iostream>
#include <cassert>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;


int my_strlen(const char *str){
    const char *ptr = str;
    while(*ptr != '\0')
        ptr++;
    return ptr - str;
}


void* my_memcopy(char *des, const char *src, size_t size){
    char *ptr_d = (char *)des;
    const char *ptr_s = src;
    while(size > 0){
        *ptr_d++ = *ptr_s++;
        size--;
    }
    return des;
}


int main(){
    char src[] = "hello world";
    char des[20] = {0};
    my_memcopy(des, src, my_strlen(src) + 1);
    printf("Test 1: src=%s, des=%s\n", src, des);
    return 0;
}