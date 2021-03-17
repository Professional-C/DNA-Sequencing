//
//  Fasta.hpp
//  src
//
//  Created by Sydney Nguyen on 3/16/21.
//

#ifndef Fasta_hpp
#define Fasta_hpp

#include <string>
#include <iostream>
#include <fstream>

class Fasta
{
public:
    Fasta(const std::string source)
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
    
    std::string getSequence() {
        return sequence;
    }
    
    std::string getHeader() {
        return header;
    }
    
private:
    std::string header;
    std::string sequence;
};




#endif /* Fasta_hpp */
