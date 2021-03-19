//
//  AminoAcidCount.hpp
//  pa4
//
//  Created by Sydney Nguyen on 3/16/21.
//

#ifndef AminoAcidCount_hpp
#define AminoAcidCount_hpp

#include "Fasta.hpp"
#include <string>
#include <unordered_map>

class AminoAcidCount
{
public:
    AminoAcidCount();
    void translate(Fasta fasta);
    
    std::string getTranslation(){
        return translation;
    }
    
    std::unordered_map<char,int>* getMap(){
        return &count;
    }
    
    int getTotal() const {
        return total;
    }
    
private:
    std::string translation = "";
    std::unordered_map<char,int> count;
    int total = 0;
};

#endif /* AminoAcidCount_hpp */
