#include "database/util/statement.h"
#include "database/util/helpers.h"
#include "database/compiler/tokenizer.h"
#include <string>
#include <map>
#include <vector>

/* TEST */
std::string serializeRow(Row& row)
{
    return std::to_string(row.id) + "_" + row.col_name + "_" + row.normalized_value;
}
/* TEST */

// INSERT
int execute_insert(File& file, std::string const& input)
{
    MappedInsert insert_mapped = map_insert(input);

    int index = 0;
    for (const auto& [key, value] : insert_mapped.column_value)
    {
        Row db_row = {index, key, value};
        index++;
        std::string seralized_row = serializeRow(db_row);
        file.append(seralized_row);
    }
    return 1;
}

// SELECT

std::string Statement::get_type()
{
    switch (this->m_type)
    {
    case SELECT:
        return "select";
    
    case INSERT:
        return "insert";

    default:
        return "";
    }
}

PrepareResult Statement::prepare_statement(std::string const& input)
{
    if (input.substr(0, 6) == "insert")
    {
        this->m_type = INSERT;
        return PREPARE_SUCCESS;
    }
    else if (input.substr(0, 6) == "select")
    {
        this->m_type = SELECT;
        return PREPARE_SUCCESS;
    }
    return PREPARE_UNRECOGNIZED_STATEMENT;
}

/*
    SYNTAX:
    INSERT (VALUE1, VALUE2)
    INTO ("COLUMN1", "COLUMN2")
    AT TABLE_NAME
*/

int Statement::execute_statement(File& file, std::string const& input)
{
    switch (this->m_type)
    {
    case INSERT:
        execute_insert(file, input);
        break;
    
    case SELECT:

        break;

    default:
        break;
    }
    return 0;
}
