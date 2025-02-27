//
// Created by User on 06.12.2024.
//

#ifndef WORLDREGIONPOPULATION_H
#define WORLDREGIONPOPULATION_H

#include <map>
#include <string>
#include <vector>
#include "WorldCountry.h"

class WorldRegionPopulation {
public:
    std::string region;
    std::map<int,long long int> year_population;

    void calcWorldRegionPopulation(std::vector<WorldCountry> worldCountry);
};
#endif //WORLDREGIONPOPULATION_H
