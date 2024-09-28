#include <fstream>
#include <string>

bool ExportLog(const std::string& logMessage) {
    std::ofstream logFile("log.txt", std::ios::app);
    if (logFile.is_open()) {
        logFile << logMessage << std::endl; 
        logFile.close(); 
        return true; 
    }
    else {
        return false; 
    }
}
