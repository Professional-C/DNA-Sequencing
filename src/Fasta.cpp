//
//  Fasta.cpp
//  src
//
//  Created by Sydney Nguyen on 3/16/21.
//

#include "Fasta.hpp"

Fasta::Fasta(const std::string source)
{
    
    std::ifstream::pos_type size;
    std::ifstream file(source, std::ios::in|std::ios::ate);
    if(file.is_open()){
        size = file.tellg();
        sequence.reserve(size);
        file.seekg(0);
        char c = file.get();
        std::getline(file,header);
        while(file.get(c)){
            if(c == 'A' || c == 'T' || c == 'C' || c == 'G'){
               sequence += c;
            }
        }
    }
}
