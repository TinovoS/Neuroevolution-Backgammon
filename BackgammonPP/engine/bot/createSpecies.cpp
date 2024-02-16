#include<vector>
#include "genome.hpp"


std::vector<Species> createSpecies(const std::vector<Genome>& population) {
    std::vector<Species> species;


    for (const auto& g : population) {
        bool foundSpecies = false;


        for (auto& s : species) {
            if (!s.genomes.empty() && g.isComparable(s.genomes[0])) {
                s.genomes.push_back(g);
                foundSpecies = true;
                break;
            }
        }


        if (!foundSpecies) {
            Species newSpecies;
            newSpecies.genomes.push_back(g);
            species.push_back(newSpecies);
        }
    }


    
    for (auto& s : species) {
        double avgFitness = s.calculateAverageFitness();
        s.cullSpecies(true); 
        for (const auto& g : s.genomes) {
            s.addToSpecies(g);
        }
    }


    return species;
}



