#include "database/compiler/tokenizer.h"
#include "database/util/helpers.h"
#include <vector>
#include <string>

MappedInsert map_insert(std::string const& input)
{
    std::map<std::string, std::string> column_value {};
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

    for (int i = 0; i < insert_columns.size(); i++)
    {
        std::string col = insert_columns[i];
        std::string val = insert_values[i];
        column_value.emplace(col, val);
    }
    MappedInsert res = {insert_table, column_value};
    return res;
}
