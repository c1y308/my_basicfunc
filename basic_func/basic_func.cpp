#include <iostream>
#include <cassert>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

/* 计算字符串的长度 */
int my_strlen(const char *str){  // input string`s address
    if(str == nullptr)
        return 0;
        
    const char *ptr = str;      // 常量指针，指向的内存不能被修改
    while(*ptr != '\0')
        ptr++;
    return ptr - str;
}


/* 内存拷贝函数 */
void* my_memcopy(char *des, char *src, size_t size){
    char *ptr_d = des;
    char *ptr_s = src;
    while(size > 0){
        *ptr_d++ = *ptr_s++;
        size--;
    }
    return des;
}

/* 内存设置函数 */
void my_memset(char *des, char value, size_t size){
    char *ptr = des;
    while(size > 0){
        *ptr++ = value;
        size--;
    }
}

/* 偏移量计算宏 */
#define my_offestof(type, member) (size_t) ( &( ((type*) 0)->member) )
typedef struct {
    char  a;
    int   b;
    short c;
    char  d;
} MyStruct;


/* 查看大端还是小端 */
void check_endianness(){
    union{
        int a = 0x1234;
        char c;
    } endianness;

    if(endianness.c == 0x34)
        printf("current platform is little-endian\n");
    else
        printf("current platform is big-endian\n");
}


/* 查看当前机器各个类型的字节数 */
void check_type_size(){
    printf("sizeof(char) = %llu\n", sizeof(char));
    printf("sizeof(short) = %llu\n", sizeof(short));
    printf("sizeof(int) = %llu\n", sizeof(int));    
    printf("sizeof(long) = %llu\n", sizeof(long));
    printf("sizeof(long long) = %llu\n", sizeof(long long));
    printf("sizeof(float) = %llu\n", sizeof(float));
    printf("sizeof(double) = %llu\n", sizeof(double));

}



int main(){
    char src[] = "hello world";
    char des[20] = {0};
    my_memcopy(des, src, my_strlen(src) + 1);
    printf("Test 1: src=%s, des=%s\n", src, des);

    size_t offest = my_offestof(MyStruct, d);
    printf("Test 2: offest of b is %llu\n", offest);

    check_endianness();
    check_type_size();
    return 0;
}