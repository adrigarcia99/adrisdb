#ifndef STATEMENT_H
#define STATEMENT_H
#include <string>
#include <map>
#include "database/storage/file.h"

enum PrepareResult {
    PREPARE_SUCCESS,
    PREPARE_UNRECOGNIZED_STATEMENT
};

enum StatementType {
    SELECT,
    INSERT
};

struct MappedInsert {
    std::string table_name;
    std::map<std::string, std::string> column_value;
};

/* TEST */
struct Row {
    int id;
    std::string col_name;
    std::string normalized_value;
};
/* TEST */

class Statement {
private:
    StatementType m_type {};

public:
    std::string get_type();
    PrepareResult prepare_statement(std::string const& input);
    int execute_statement(File& file, std::string const& input);
};

#endif
