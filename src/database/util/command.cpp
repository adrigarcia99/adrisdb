#include <string>
#include "database/util/command.h"

MetaCommandResult evaluate_meta_command(std::string input)
{
    if (input == "exit") return META_COMMAND_EXIT;
    else return META_COMMAND_SUCCESS;
}
