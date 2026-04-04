#include "my_string.hpp"

using namespace my_string;
size_t my_string::strlen(const char *str){
    if(str == nullptr)
        return 0;
    
    size_t len = 0;
    while(str[len] != '\0'){len++;}

    return len;

}


MyString::MyString(const char *str){
    size_t len = strlen(str);
    char *arr = new char[len + 1];
    
    if(str){
        strcpy(arr, str);
    }

    arr[len] = '\0';
    ch = arr;
}


MyString::MyString(const MyString &other){
    size_t len = strlen(other.ch);
    ch = new char[len + 1];
    strcpy(ch, other.ch);
}


MyString& MyString::operator=(const MyString &other){
    if(this == &other)
        return *this;

    delete[] ch;

    ch = new char[strlen(other.ch) + 1];
    strcpy(ch, other.ch);

    return *this;
}


MyString::~MyString(){
    delete[] ch;
}


void test_strlen() {
    assert(my_string::strlen(nullptr) == 0);
    assert(my_string::strlen("") == 0);
    assert(my_string::strlen("hello") == 5);
    assert(my_string::strlen("hello world") == 11);
    std::cout << "test_strlen passed!" << std::endl;
}


void test_default_constructor() {
    MyString s1;
    MyString s2(nullptr);
    std::cout << "test_default_constructor passed!" << std::endl;
}


void test_constructor_with_string() {
    MyString s1("hello");
    MyString s2("hello world");
    MyString s3("");
    std::cout << "test_constructor_with_string passed!" << std::endl;
}


void test_copy_constructor() {
    MyString s1("hello");
    MyString s2(s1);
    std::cout << "test_copy_constructor passed!" << std::endl;
}


void test_assignment_operator() {
    MyString s1("hello");
    MyString s2("world");
    s2 = s1;
    
    MyString s3("test");
    s3 = s3;
    std::cout << "test_assignment_operator passed!" << std::endl;
}


void test_self_assignment() {
    MyString s1("hello");
    s1 = s1;
    std::cout << "test_self_assignment passed!" << std::endl;
}


void test_chained_assignment() {
    MyString s1("hello");
    MyString s2("world");
    MyString s3("test");
    
    s3 = s2 = s1;
    std::cout << "test_chained_assignment passed!" << std::endl;
}


void run_all_tests() {
    std::cout << "=== Running MyString Tests ===" << std::endl;
    
    test_strlen();
    test_default_constructor();
    test_constructor_with_string();
    test_copy_constructor();
    test_assignment_operator();
    test_self_assignment();
    test_chained_assignment();
    
    std::cout << "=== All Tests Passed! ===" << std::endl;
}


int main(void){
    run_all_tests();
    return 0;
}
