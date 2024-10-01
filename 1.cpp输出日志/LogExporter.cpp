//LogExporter.cpp
#include "LogExporter.h"

// 写入字符串到文件
void LogStringToFile(const std::string& data, const std::string& filePath) {
    std::ofstream logFile(filePath, std::ios::app);
    if (logFile.is_open()) {
        logFile << data << std::endl;
        logFile.close();
    } else {
        std::cerr << "Failed to open file at " << filePath << std::endl;
    }
}

// 写入整数到文件
void LogIntToFile(int data, const std::string& filePath) {
    std::ofstream logFile(filePath, std::ios::app);
    if (logFile.is_open()) {
        logFile << data << std::endl;
        logFile.close();
    } else {
        std::cerr << "Failed to open file at " << filePath << std::endl;
    }
}

// 写入指针所指向的数据到文件
void LogPointerToFile(const int* dataPtr, const std::string& filePath) {
    if (dataPtr == nullptr) {
        std::cerr << "Null pointer provided." << std::endl;
        return;
    }

    std::ofstream logFile(filePath, std::ios::app);
    if (logFile.is_open()) {
        logFile << *dataPtr << std::endl; // 解引用指针并输出
        logFile.close();
    } else {
        std::cerr << "Failed to open file at " << filePath << std::endl;
    }
}
