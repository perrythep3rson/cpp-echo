#include <iostream>
#include <vector>
#include <map>
#include <string>


const std::map <std::string, std::string> escapeReplacements = {
    {"\\v", "\v"},
    {"\\t", "\t"},
    {"\\r", "\r"},
    {"\\n", "\n"},
    {"\\c", ""},
    {"\\b", "\b"},
    {"\\a", "\a"}
};
const std::vector <std::string> flags = {"-e", "-E", "-n"};

void replaceEscapeSequences(std::string& str);

int main(int argc, char** argv){

    if(argc < 2){
        std::cerr << "Please provide an argument." << std::endl;
        return 1;
    }

    std::vector<std::string> arguments(argv + 1, argv + argc);

    for (std::string argument : arguments) {

        replaceEscapeSequences(argument);

        std::cout << argument;
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