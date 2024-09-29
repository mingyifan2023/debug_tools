#include "framework.h"
#include "Project6.h"
#include <iostream>
#include "LogExporter.h"


// 示例使用
int main() {
    // 记录基本类型
    LogToFile(123);
    LogToFile("Hello, World!");
    LogToFile("-----------------------------------------------------");
    // 记录指针
    int value = 42;
    LogToFile(&value);
    LogToFile("-----------------------------------------------------");
    // 记录数组
    int arr[] = { 1, 2, 3, 4, 5 };
    LogArrayToFile(arr, 5);
    LogToFile("-----------------------------------------------------");
    // 记录 STL 容器
    std::vector<int> vec = { 10, 20, 30 };
    LogToFile(vec);
    LogToFile("-----------------------------------------------------");
    std::list<std::string> lst = { "apple", "banana", "cherry" };
    LogToFile(lst);
    LogToFile("-----------------------------------------------------");
    std::map<int, std::string> m = { {1, "one"}, {2, "two"} };
    LogToFile(m);
    LogToFile("-----------------------------------------------------");
    std::set<double> s = { 1.1, 2.2, 3.3 };
    LogToFile(s);
    LogToFile("-----------------------------------------------------");
    // 记录用户定义类型
    MyStruct myStruct = { 1, "Example" };
    LogToFile(myStruct);
    LogToFile("-----------------------------------------------------");

    MyStruct* structPtr = &myStruct; // 获取指向结构体的指针

    // 记录结构体指针
    LogToFile(structPtr);
    LogToFile("-----------------------------------------------------");
    // 记录空指针的情况
    MyStruct* nullPtr = nullptr;
    LogToFile(nullPtr);
    LogToFile("-----------------------------------------------------");


    return 0;
}
