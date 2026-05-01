#include <iostream>
#include <string>
#include "database/util/command.h"
#include "database/util/statement.h"

int main()
{
    std::cout << "Starting AdrisDB" << '\n';
    
    std::string input {};

    while (true)
    {
        std::cout << "db > ";
        std::getline(std::cin, input);

        if (input.front() == '.')
        {
            std::string meta_commmand = input.substr(1, input.length());
            switch (evaluate_meta_command(meta_commmand))
            {
            case META_COMMAND_EXIT:
                std::cout << "Ending connection" << '\n';
                return 0;
            
            case META_COMMAND_SUCCESS:
                continue;

            case META_COMMAND_UNRECOGNIZED_COMMAND:
                continue;

            default:
                continue;
            }
        }
        else
        {
            Statement statement {};
            switch (statement.prepare_statement(input))
            {
            case PREPARE_SUCCESS:
                std::cout << "Processing request of type: " << statement.get_type() << '\n';
                break;
            
            case PREPARE_UNRECOGNIZED_STATEMENT:
                std::cout << "Unrecognized statement" << '\n';
                break;

            default:
                break;
            }

            statement.execute_statement(input);
        }
    }

    return 0;
}
