//
//  AminoAcidCount.cpp
//  pa4
//
//  Created by Sydney Nguyen on 3/16/21.
//

#include "AminoAcidCount.hpp"
#include "Fasta.hpp"

int convertBase(char c){
    if(c == 'T'){
        return 0;
    }
    else if (c == 'C'){
        return 1;
    }
    else if (c == 'A'){
        return 2;
    }
    else{ // G
        return 3;
    }
}

void AminoAcidCount::translate(Fasta fasta) {
    std::string table[24][4] = {
                        { "0", "0", "1", "0" }, // 0
                        { "2", "0", "1", "0" }, // 1
                        { "0", "0", "1", "3" }, // 2
                        { "4", "9", "14", "19"}, // 3 First Letter
                        { "5", "6", "7", "8" }, // 4 T*
                        { "F", "F", "L", "L" }, // 5
                        { "S", "S", "S", "S" }, // 6
                        { "Y", "Y", "X", "X" }, // 7
                        { "C", "C", "X", "W" }, // 8
                        { "10", "11", "12", "13" }, // 9 C*
                        { "L", "L", "L", "L" }, // 10
                        { "P", "P", "P", "P" }, // 11
                        { "H", "H", "Q", "Q" }, // 12
                        { "R", "R", "R", "R" }, // 13
                        { "15", "16", "17", "18" }, // 14 A*
                        { "I", "I", "I", "M" }, // 15
                        { "T", "T", "T", "T" }, // 16
                        { "N", "N", "K", "K" }, // 17
                        { "S", "S", "R", "R" }, // 18
                        { "20", "21", "22", "23" }, // 19 G*
                        { "V", "V", "V", "V" }, // 20
                        { "A", "A", "A", "A" }, // 21
                        { "D", "D", "E", "E" }, // 22
                        { "G", "G", "G", "G" }, // 23
                      };
    
    std::string sequence = fasta.getSequence();
    std::string codon;
    int state = 0;
    int base = 0;
    int tempCounter = 0;
    
    for(char& c : sequence){
        tempCounter++;
        base = convertBase(c);
        if(state < 3){
            state = stoi(table[state][base]);
            //std::cout << state << std::endl;
            if(state == 3){
                //std::cout << tempCounter/3 << std::endl;
                count["M"] += 1;
                total++;
            }
        }
        else{
            codon += c;
            if(codon.size() == 3){
                //std::cout << codon << std::endl;
                std::string getAmino = table[state][base];
                if(getAmino == "X"){ // Stop Codon
                    state = 0;
                }
                else{
                    translation += getAmino;
                    total++;
                    state = 3;
                }
                count[std::string(1,getAmino[0])] += 1;
                codon.clear();
            }
            else{
                state = stoi(table[state][base]);
            }
        }
    }
    
}

AminoAcidCount::AminoAcidCount()
{
    count["A"] = 0;
    count["C"] = 0;
    count["D"] = 0;
    count["E"] = 0;
    count["F"] = 0;
    count["G"] = 0;
    count["H"] = 0;
    count["I"] = 0;
    count["K"] = 0;
    count["L"] = 0;
    count["M"] = 0;
    count["N"] = 0;
    count["P"] = 0;
    count["Q"] = 0;
    count["R"] = 0;
    count["S"] = 0;
    count["T"] = 0;
    count["V"] = 0;
    count["W"] = 0;
    count["Y"] = 0;
}
