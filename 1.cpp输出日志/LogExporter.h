//#include <fstream>
//#include <string>
//#include <iostream>
//
//bool ExportLog(const std::string& logMessage) {
//    const std::string filePath = "C:\\Users\\user\\Downloads\\cpp_demo\\log.txt"; // 定义路径
//    std::cout << "Attempting to write to: " << filePath << std::endl; // 调试信息
//
//    std::ofstream logFile(filePath, std::ios::app); // 打开文件以附加模式
//
//    if (logFile.is_open()) {
//        logFile << logMessage << std::endl; // 写入日志
//        logFile.close(); // 关闭文件
//        return true; // 成功
//    }
//    else {
//        std::cerr << "Failed to open file at " << filePath << std::endl; // 错误信息
//        return false; // 失败
//    }
//}



// 使用模板泛型，通用化
//涵盖了基本数据类型、指针、数组、STL 容器（如 std::vector、std::list 等）以及用户定义的结构体。
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <type_traits>
// 定义日志文件路径
const std::string filePath = "C:\\Users\\user\\Downloads\\cpp_demo\\log.txt";




// 主日志记录模板
template<typename T>
void LogToFile(const T& message) {
    std::ofstream logFile(filePath, std::ios::app); // 打开文件以附加模式
    if (logFile.is_open()) {
        logFile << message << std::endl; // 写入日志
        logFile.close(); // 关闭文件
    }
    else {
        std::cerr << "Failed to open file at " << filePath << std::endl;
    }
}

// 特化处理指针类型
template<typename T>
void LogToFile(T* ptr) {
    std::ofstream logFile(filePath, std::ios::app);
    if (logFile.is_open()) {
        logFile << "Pointer Address: " << ptr << std::endl; // 写入指针地址
        if (ptr) {
            logFile << "Pointer Value: " << *ptr << std::endl; // 写入指针所指向的值
        }
        else {
            logFile << "Pointer Value: nullptr" << std::endl; // 明确写入 nullptr
        }
        logFile.close();
    }
    else {
        std::cerr << "Failed to open file at " << filePath << std::endl;
    }
}

// 用于记录数组的函数
template<typename T>
void LogArrayToFile(const T* array, size_t size) {
    std::ofstream logFile(filePath, std::ios::app);
    if (logFile.is_open()) {
        logFile << "Array Elements: ";
        for (size_t i = 0; i < size; ++i) {
            logFile << array[i] << (i < size - 1 ? ", " : "");
        }
        logFile << std::endl;
        logFile.close();
    }
    else {
        std::cerr << "Failed to open file at " << filePath << std::endl;
    }
}

// 处理 STL 容器
template<typename T>
void LogToFile(const std::vector<T>& vec) {
    std::ofstream logFile(filePath, std::ios::app);
    if (logFile.is_open()) {
        logFile << "Vector Elements: ";
        for (const auto& item : vec) {
            logFile << item << " "; // 可以自定义分隔符
        }
        logFile << std::endl;
        logFile.close();
    }
    else {
        std::cerr << "Failed to open file at " << filePath << std::endl;
    }
}

template<typename T>
void LogToFile(const std::list<T>& lst) {
    std::ofstream logFile(filePath, std::ios::app);
    if (logFile.is_open()) {
        logFile << "List Elements: ";
        for (const auto& item : lst) {
            logFile << item << " ";
        }
        logFile << std::endl;
        logFile.close();
    }
    else {
        std::cerr << "Failed to open file at " << filePath << std::endl;
    }
}

template<typename K, typename V>
void LogToFile(const std::map<K, V>& m) {
    std::ofstream logFile(filePath, std::ios::app);
    if (logFile.is_open()) {
        logFile << "Map Elements: ";
        for (const auto& pair : m) {
            logFile << "[" << pair.first << " : " << pair.second << "] ";
        }
        logFile << std::endl;
        logFile.close();
    }
    else {
        std::cerr << "Failed to open file at " << filePath << std::endl;
    }
}

template<typename T>
void LogToFile(const std::set<T>& s) {
    std::ofstream logFile(filePath, std::ios::app);
    if (logFile.is_open()) {
        logFile << "Set Elements: ";
        for (const auto& item : s) {
            logFile << item << " ";
        }
        logFile << std::endl;
        logFile.close();
    }
    else {
        std::cerr << "Failed to open file at " << filePath << std::endl;
    }
}



// 用户定义结构体的示例
struct MyStruct {
    int id;
    std::string name;

    // 重载输出运算
      // 重载输出运算符以便于日志记录
    friend std::ostream& operator<<(std::ostream& os, const MyStruct& myStruct) {
        os << "MyStruct [ID: " << myStruct.id << ", Name: " << myStruct.name << "]";
        return os;
    }
};

// 特化处理用户定义结构体
template<>
void LogToFile(const MyStruct& myStruct) {
    std::ofstream logFile(filePath, std::ios::app);
    if (logFile.is_open()) {
        logFile << myStruct << std::endl; // 利用重载的输出运算符
        logFile.close();
    }
    else {
        std::cerr << "Failed to open file at " << filePath << std::endl;
    }
}

