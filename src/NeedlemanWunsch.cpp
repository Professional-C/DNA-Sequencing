//
//  NeedlemanWunsch.cpp
//  pa4
//
//  Created by Sydney Nguyen on 3/18/21.
//

#include "NeedlemanWunsch.hpp"
#include <vector>
#include <iostream>

void NeedlemanWunsch::performNW()
{
    
    std::vector<std::vector<short>> scores(f2.getSequence().size()+1, std::vector<short>(f1.getSequence().size()+1));
    std::vector<std::vector<Direction>> dirs(f2.getSequence().size()+1, std::vector<Direction>(f1.getSequence().size()+1));
    
    for(size_t i = 0; i < scores.size(); i++){
        scores[i][0] = -i;
        dirs[i][0] = LEFT;
    }
    for(size_t j = 0; j < scores[0].size(); j++){
        scores[0][j] = -j;
        dirs[0][j] = UP;
    }
    
    std::string seq1 = f1.getSequence();
    std::string seq2 = f2.getSequence();
    
    
    for(size_t i = 1; i < scores.size(); i++){
        for(size_t j = 1; j < scores[0].size(); j++){
            short match = seq1.at(j-1)==seq2.at(i-1)? 1 : -1;
            short d = scores[i-1][j-1] + match;
            short l = scores[i][j-1]-1;
            short u = scores[i-1][j]-1;
            int max = std::max(d,std::max(l,u));
            scores[i][j] = max;
            if (max == d){
                dirs[i][j] = DIAGONAL;
            }
            else if(max == l){
                dirs[i][j] = LEFT;
            }
            else {
                dirs[i][j] = UP;
            }
        }
    }
    
    score = scores[scores.size()-1][scores[0].size()-1];
    
    int i = scores.size()-1;
    int j = scores[0].size()-1;
    while( (i != 0) || (j != 0)){
        Direction dir = dirs[i][j];
        if( i <= 0) {
            dir = LEFT;
        }
        else if ( j <= 0) {
            dir = UP;
        }
        else {
            dir = dirs[i][j];
        }
        if(dir == DIAGONAL){
            solA += seq1.at(j-1);
            solB += seq2.at(i-1);
            i -= 1;
            j -= 1;
        }
        else if(dir == LEFT){
            solA += seq1.at(j-1);
            solB += "_";
            j -= 1;
        }
        else if(dir == UP){
            solA += "_";
            solB += seq2.at(i-1);
            i -= 1;
        }
    }
    
    std::reverse(solA.begin(),solA.end());
    std::reverse(solB.begin(),solB.end());
    
    for(int i = 0; i < solA.size(); i++){
        if(solA.at(i) == solB.at(i)){
            pipes += "|";
        }
        else{
            pipes += " ";
        }
    }
    
    
    
}

void NeedlemanWunsch::print(){
    std::ofstream output("match.txt");
    output << "A: " << f1.getHeader() << std::endl;
    output << "B: " << f2.getHeader() << std::endl;
    output << "Score: " << score << std::endl << std::endl;
    
    int start = 0;
    int num = 70;
    while(start < solA.size()){
        if(start+num > solA.size()){
            num = solA.size()-start;
        }
        output << solA.substr(start,num) << std::endl;
        output << pipes.substr(start,num) << std::endl;
        output << solB.substr(start,num) << std::endl << std::endl;
        start += 70;
    }
    
}



