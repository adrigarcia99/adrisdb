#include "database/util/statement.h"
#include "database/util/helpers.h"
#include <string>
#include <map>
#include <vector>

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

int Statement::execute_statement(std::string const& input)
{
    switch (this->m_type)
    {
    case INSERT:
        
        break;
    
    case SELECT:

        break;

    default:
        break;
    }
    return 0;
}

std::map<std::string, std::string> map_insert(std::string const& input)
{
    std::map<std::string, std::string> insert_sentence {};
    std::vector<std::string> insert_values {};
    std::vector<std::string> insert_columns {};

    // First we get the values
    size_t start_values = input.find('(');
    size_t end_values = input.find(')', start_values);
    std::string values_str = input.substr(start_values + 1, end_values - start_values - 1);

    size_t pos_value {0};
    std::string insert_value {};
    
    while ((pos_value = values_str.find(',')) != std::string::npos)
    {
        insert_value = values_str.substr(0, pos_value);
        insert_values.push_back(trim(insert_value));
        values_str.erase(0, pos_value + 1);
    }
    // Push last element
    if (!values_str.empty()) {
        insert_values.push_back(trim(values_str));
    }

    // Then the column names
    size_t start_columns = input.find('(', end_values);
    size_t end_columns = input.find(')', start_columns);
    std::string columns_str = input.substr(start_columns + 1, end_columns - start_columns - 1);
    
    size_t pos_column {0};
    std::string insert_column {};
    
    while ((pos_column = columns_str.find(',')) != std::string::npos)
    {
        insert_column = columns_str.substr(0, pos_column);
        insert_columns.push_back(trim(insert_column));
        columns_str.erase(0, pos_column + 1);
    }
    // Push last element
    if (!columns_str.empty()) {
        insert_columns.push_back(trim(columns_str));
    }

    // Finally the table name
    size_t pos_table = input.rfind(" at ");
    std::string insert_table = trim(input.substr(pos_table + 4));

    return insert_sentence;
}
