//
//  Fasta.cpp
//  src
//
//  Created by Sydney Nguyen on 3/16/21.
//

#include "Fasta.hpp"
#include <string>

Fasta::Fasta(const std::string source)
{
    
    std::ifstream::pos_type size;
    std::ifstream file(source, std::ios::in|std::ios::ate);
    if(file.is_open()){
        size = file.tellg();
        sequence.reserve(size);
        file.seekg(0);
        file.get();
        std::getline(file,header);
        std::string line;
        while(getline(file,line)){
            line.erase(std::remove(line.begin(),line.end(), 'N'), line.end());
            sequence += line;
        }
    }
}
