
#include <fstream>
#include <string>
#include <iostream>

bool ExportLog(const std::string& logMessage) {
    const std::string filePath = "C:\\Users\\user\\Downloads\\cpp_demo\\log.txt"; // 定义路径
    std::cout << "Attempting to write to: " << filePath << std::endl; // 调试信息

    std::ofstream logFile(filePath, std::ios::app); // 打开文件以附加模式

    if (logFile.is_open()) {
        logFile << logMessage << std::endl; // 写入日志
        logFile.close(); // 关闭文件
        return true; // 成功
    }
    else {
        std::cerr << "Failed to open file at " << filePath << std::endl; // 错误信息
        return false; // 失败
    }
}
