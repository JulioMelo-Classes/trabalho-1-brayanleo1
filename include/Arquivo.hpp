#ifndef Arquivo_hpp
#define Arquivo_hpp

#include <vector>
#include <iostream>

class Arquivo{
    private:
        std::string local;
    public:
        Arquivo(std::string local_);
        std::vector<std::string> lerLinhas();
};
#endif //Arquivo_hpp