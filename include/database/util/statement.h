#ifndef STATEMENT_H
#define STATEMENT_H
#include <string>

enum PrepareResult {
    PREPARE_SUCCESS,
    PREPARE_UNRECOGNIZED_STATEMENT
};

enum StatementType {
    SELECT,
    INSERT
};

class Statement {
private:
    StatementType m_type {};

public:
    std::string get_type();
    PrepareResult prepare_statement(std::string input);
};

#endif
