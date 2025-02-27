//
// Created by User on 13.11.2024.
//

#ifndef WORLDPOPULATION_H
#define WORLDPOPULATION_H
#include <string>
#include <vector>
#include <map>

#include "country.h"

struct WorldPopulation {
    std::vector<Country> countries;
    std::map<int,long long int> yearPopulation;

    void readCountryPopulationFromFile(std::string nameFile);

    void calcWorldPopulation();

    void writeCountryPopulationToFile(std::string nameFile);

};

#endif //WORLDPOPULATION_H
