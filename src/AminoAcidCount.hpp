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
#include <map>

class AminoAcidCount
{
public:
    AminoAcidCount();
    void translate(Fasta fasta);
    
    std::string getTranslation(){
        return translation;
    }
    
    std::map<std::string,int>* getMap(){
        return &count;
    }
    
    int getTotal() {
        return total;
    }
    
private:
    std::string translation = "";
    std::map<std::string,int> count;
    int total = 0;
};

#endif /* AminoAcidCount_hpp */
