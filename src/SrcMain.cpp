#include "SrcMain.h"
#include "Fasta.hpp"
#include "AminoAcidCount.hpp"
#include "NeedlemanWunsch.hpp"
#include <iostream>



void ProcessCommandArgs(int argc, const char* argv[])
{
    if(argc == 2){
        std::string file = argv[1];
        Fasta fasta = Fasta(file);
        AminoAcidCount aac = AminoAcidCount();
        aac.translate(fasta);
        std::map<std::string,int>* map = aac.getMap();
        std::ofstream output("amino.txt");
        output << fasta.getHeader() << std::endl;
        output << "Total amino acids produced: " << aac.getTotal() << std::endl;
        output << "(A) Alanine: " << map->at("A") << std::endl;
        output << "(C) Cysteine: " << map->at("C") << std::endl;
        output << "(D) Aspartic acid: " << map->at("D") << std::endl;
        output << "(E) Glutamic acid: " << map->at("E") << std::endl;
        output << "(F) Phenylalanine: " << map->at("F") << std::endl;
        output << "(G) Glycine: " << map->at("G") << std::endl;
        output << "(H) Histidine: " << map->at("H") << std::endl;
        output << "(I) Isoleucine: " << map->at("I") << std::endl;
        output << "(K) Lysine: " << map->at("K") << std::endl;
        output << "(L) Leucine: " << map->at("L") << std::endl;
        output << "(M) Methionine: " << map->at("M") << std::endl;
        output << "(N) Asparagine: " << map->at("N") << std::endl;
        output << "(P) Proline: " << map->at("P") << std::endl;
        output << "(Q) Glutamine: " << map->at("Q") << std::endl;
        output << "(R) Arginine: " << map->at("R") << std::endl;
        output << "(S) Serine: " << map->at("S") << std::endl;
        output << "(T) Threonine: " << map->at("T") << std::endl;
        output << "(V) Valine: " << map->at("V") << std::endl;
        output << "(W) Tryptophan: "<< map->at("W")  << std::endl;
        output << "(Y) Tyrosine: " << map->at("Y") << std::endl;
        
    }
    else if(argc == 3){
        std::string file1 = argv[1];
        std::string file2 = argv[2];
        Fasta fasta1 = Fasta(file1);
        Fasta fasta2 = Fasta(file2);
        NeedlemanWunsch nw = NeedlemanWunsch(fasta1, fasta2);
        nw.performNW();
        nw.print();
    }
}

