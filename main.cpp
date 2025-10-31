#include <iostream>
#include <vector>

void formatNewLines(std::string& str);

int main(int argc, char** argv){

    if(argc < 2){
        std::cerr << "Please provide an argument." << std::endl;
        return 1;
    }

    std::vector<std::string> arguments(argv + 1, argv + argc);

    for (std::string argument : arguments) {
           std::size_t pos = 0;
           const std::string from = "\\n";
           const std::string to = "\n";

           while ((pos = argument.find(from, pos)) != std::string::npos) {
               argument.replace(pos, from.length(), to);
               pos += to.length();
           }
           std::cout << argument << std::endl;
    }
    return 0;
}