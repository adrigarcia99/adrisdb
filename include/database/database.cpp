#include "database.h"

int Database::getVersion() {
    return this->version;
}

void Database::setVersion(int version) {
    this->version = version;
}
