#include <string>
#include <map>

struct MappedInsert {
    std::string table_name;
    std::map<std::string, std::string> column_value;
};

MappedInsert map_insert(std::string const& input);
