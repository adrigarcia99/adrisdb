#ifndef DATABASE_H
#define DATABASE_H

class Database {
private:
    int version;

public:
    int getVersion();
    void setVersion(int version);
};

#endif
