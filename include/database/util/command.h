#ifndef COMMAND_H
#define COMMAND_H

enum MetaCommandResult {
    META_COMMAND_SUCCESS,
    META_COMMAND_UNRECOGNIZED_COMMAND,
    META_COMMAND_EXIT
};

MetaCommandResult evaluate_meta_command(std::string input);

#endif
