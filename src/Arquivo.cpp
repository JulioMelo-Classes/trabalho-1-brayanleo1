#include <fstream>
#include <iostream>
#include <string>

#include "Arquivo.hpp"

using namespace std;

Arquivo::Arquivo(std::string local_){
    local = local_;
}

std::vector<std::string> Arquivo::lerLinhas(){
    ifstream file1;
    file1.open(local);
    std::vector<string> v;
    for(int i=0; i<3; i++){
        string texto;
        std::getline(file1, texto);
        v.push_back(texto);
    }
    file1.close();

    return v;
}