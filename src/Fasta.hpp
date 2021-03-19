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
    Fasta(std::string source);
    
//    Fasta(const Fasta& oldFasta)
//        :header(oldFasta.header),
//         sequence(oldFasta.sequence)
//    {}
//
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
