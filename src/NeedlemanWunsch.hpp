//
//  NeedlemanWunsch.hpp
//  pa4
//
//  Created by Sydney Nguyen on 3/18/21.
//

#ifndef NeedlemanWunsch_hpp
#define NeedlemanWunsch_hpp

#include "Fasta.hpp"

#endif /* NeedlemanWunsch_hpp */

class NeedlemanWunsch
{
public:
    
    enum Direction : char { UP, LEFT, DIAGONAL };
    
    NeedlemanWunsch(Fasta fasta1, Fasta fasta2)
        :f1(fasta1),
        f2(fasta2)
    {}
    
    void performNW();
    
    void print();
    
    
private:
    Fasta f1;
    Fasta f2;
    std::string solA;
    std::string solB;
    int score = 0;
    std::string pipes;
};

