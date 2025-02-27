//
// Created by User on 06.12.2024.
//
#include "Program.h"

#include <iostream>
#include <math.h>

#include "readCountryFeatureFromFile.h"
#include "country.h"
#include "readCountryFromFile.h"
#include "WorldRegionPopulation.h"

void Program::readCountryPopulationFromFile(const std::string &fileOfCountries, const std::string &fileOfFeatures) {

    Program::countryFeatures = readCountryFeatureFromFile(fileOfFeatures);

    Program::countries = readCountryFromFile(fileOfCountries);

    for (int i = 0;i < Program::countryFeatures.size(); i++) {
        WorldCountry tmp;
        tmp.countryFeature = countryFeatures[i];
        tmp.yearPopulation = countries[i].yearPopulation;
        tmp.сountryName = countries[i].contryName;

        Program::worldCountrys.push_back(tmp);
    }
}

std::vector<WorldCountry> Program::findCountriesByIncome(IncomeGroup incomeGroup) {
    std::vector<WorldCountry> result;

    for (auto to : Program::worldCountrys) {
        if (to.countryFeature.IncomeGroup == incomeGroup ) {
            result.push_back(to);
        }
    }

    return result;
}

std::vector<std::string> Program::findUniqueRegion() {
    std::vector<std::string> result;

    for (auto to : Program::countryFeatures) {
        bool f = 1;

        for( auto to2 : result ) {
            if( to2 ==  to.region ) {
                f = 0;
            }
        }

        if (f) {
            result.push_back(to.region);
        }
    }

    return result;
}

std::vector<WorldCountry> Program::findUniqueRegion(const std::string &region) {
    std::vector<WorldCountry> result;

    for (auto to : Program::worldCountrys) {
        if (region == to.countryFeature.region) {
            result.push_back(to);
        }
    }
    return result;
}

void Program::writeWorldRegionPopulationToFile(const std::string &file) {

    std::ofstream fout(file);

    fout << "Region ; ";

    for (int i = 1960; i <= 2018; ++ i) {
        fout << i << "; ";
    }

    fout << "\n";

    std::vector<std::string> regions = findUniqueRegion();

    for (auto region : regions) {


        WorldRegionPopulation tmp;
        tmp.region = region;

        std::vector<WorldCountry> v = findUniqueRegion(region);

        tmp.calcWorldRegionPopulation(v);

        fout << tmp.region << "; ";

        for (auto to : tmp.year_population ) {
            fout << to.second << "; ";
        }

        fout << '\n';
    }
}
