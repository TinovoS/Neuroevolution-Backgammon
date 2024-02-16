#include "species.hpp"
#include <algorithm>

double species::calculateAverageFitness() {
    double totalFitness = 0.0;
    for (const auto& genome : genomes) {
        totalFitness += genome->getFitness();
    }
    averageFitness = totalFitness / genomes.size();
    return averageFitness;
}

void species::cullSpecies(bool cutToOne) {
    std::sort(genomes.begin(), genomes.end(), [](Genome* a, Genome* b) {
        return a->getFitness() > b->getFitness();
    });
    if (cutToOne && genomes.size() > 1) {
        for (size_t i = 1; i < genomes.size(); ++i) {
            delete genomes[i];
        }
        genomes.erase(genomes.begin() + 1, genomes.end());
    }
}

void species::addToSpecies(Genome* g) {
    genomes.push_back(g);
}

