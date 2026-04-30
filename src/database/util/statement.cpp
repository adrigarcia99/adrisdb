#include <string>
#include "database/util/statement.h"

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

PrepareResult Statement::prepare_statement(std::string input)
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
