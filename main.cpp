#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>


const std::map <std::string, std::string> escapeReplacements = {
    {"\\v", "\v"},
    {"\\t", "\t"},
    {"\\r", "\r"},
    {"\\n", "\n"},
    {"\\b", "\b"},  //needs special implementation to remove all spaces between text
};
const std::vector <std::string> flags = {"-e", "-E", "-n"};

void replaceEscapeSequences(std::string& str);

int main(int argc, char** argv){

    bool escapeFlag = false;
    bool noEscapeFlag = false;
    bool noNewLineFlag = false;

    if(argc < 2){
        std::cerr << "Please provide an argument." << std::endl;
        return 1;
    }

    std::vector<std::string> arguments(argv + 1, argv + argc);

    for (std::string argument : arguments) {

        if(argument == flags[0]){ //-e, acknowledge escape sequences
            escapeFlag = true;
            noEscapeFlag = false;
            continue;
        }
        else if(argument == flags[1]){ //-E, do not acknowledge escape sequences
            noEscapeFlag = true;
            escapeFlag = false;
            continue;
        }
        else if(argument == flags[2]){ //-n, do not output the trailing newline
            noNewLineFlag = true;
            continue;
        }
        else {
            break;
        }
    }

    for (std::string& argument : arguments) {

        auto it = std::find(flags.begin(), flags.end(), argument);
        
        if(it != flags.end()){
            continue;
        }

        if(escapeFlag && !noEscapeFlag){
            replaceEscapeSequences(argument);
        }

        if(argument.find("\\c") != std::string::npos){
            argument = argument.substr(0, argument.find("\\c"));
            std::cout << argument;

            if(!noNewLineFlag)
            {
                std::cout << std::endl;
            }

            return 0;
        }

        std::cout << argument;

        if(argument != arguments.back()){
            std::cout << " ";
        } 
    }

    if(!noNewLineFlag)
    {
        std::cout << std::endl;
    }

    return 0;
}

void replaceEscapeSequences(std::string& str) {

    for(const auto& pair : escapeReplacements) {
        const std::string& from = pair.first;
        const std::string& to = pair.second;
        std::size_t position = 0;

        while ((position = str.find(from, position)) != std::string::npos) {
            str.replace(position, from.length(), to);
            position += to.length();
        }
    }
}

