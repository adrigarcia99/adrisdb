#ifndef BYTE_BUFFER_H
#define BYTE_BUFFER_H
#include <vector>

class ByteBuffer {
private:
    int read_offset {};
    int write_offset {};
    std::vector<int> buffer {};

public:
    void read();
    void write();
};

#endif
