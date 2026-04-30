#ifndef DATABASE_H
#define DATABASE_H
#include <string>

class Database {
private:
    std::string m_base_path { "C:\\dev\\database\\filedata.txt" };

public:
    Database() {}
    std::string get_base_path();
};

#endif
