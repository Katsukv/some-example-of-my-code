//
// Created by User on 06.12.2024.
//

#ifndef WORLDCOUNTRY_H
#define WORLDCOUNTRY_H

#include <map>

#include "CountryFeature.h"

class WorldCountry {
public:
    std::string сountryName;
    CountryFeature countryFeature;
    std::map<int, long long int> yearPopulation;
};

#endif //WORLDCOUNTRY_H
