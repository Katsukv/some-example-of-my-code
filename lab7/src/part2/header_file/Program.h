//
// Created by User on 06.12.2024.
//

#ifndef PROGRAM_H
#define PROGRAM_H

#include <vector>
#include <string>

#include "CountryFeature.h"
#include "WorldCountry.h"
#include "country.h"

class Program {
private:
    std::vector<CountryFeature> countryFeatures;
    std::vector<Country> countries;
    std::vector<WorldCountry> worldCountrys;
public:
    void readCountryPopulationFromFile(const std::string &fileOfCountries, const std::string &fileOfFeatures);

    std::vector<WorldCountry> findCountriesByIncome(IncomeGroup incomeGroup);

    std::vector<std::string> findUniqueRegion();

    std::vector<WorldCountry> findUniqueRegion(const std::string &region);

    void writeWorldRegionPopulationToFile(const std::string &file);
};
#endif //PROGRAM_H
