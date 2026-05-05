#ifndef FILE_H
#define FILE_H
#include <vector>
#include <string>

class File {
private:
    std::string m_path {};
    int m_read_offset {};
    int m_write_offset {};
    std::vector<int> m_buffer {};

public:
    File(std::string path) : m_path { path } {}
    void read();
    void write(std::string content);
    void append(std::string content);
    void loadFile();
};

#endif
