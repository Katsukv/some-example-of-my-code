//
// Created by User on 13.11.2024.
//

#include "WorldPopulation.h"
#include <fstream>
#include <iostream>

#include "WorldCountry.h"
#include "readCountryFromFile.h"

//#include "spdlog/spdlog.h"


void WorldPopulation::calcWorldPopulation() {
    for (auto to: WorldPopulation::countries) {
        for( auto to2: to.yearPopulation) {
            WorldPopulation::yearPopulation[to2.first] += to2.second;
        }
    }
}

void WorldPopulation::readCountryPopulationFromFile(std::string nameFile) {
    WorldPopulation::countries = readCountryFromFile(nameFile);
}

void WorldPopulation::writeCountryPopulationToFile(std::string nameFile) {
    std::ofstream fout;
    fout.open(nameFile, std::ios::app);

    fout << ";result:;";
    for (auto to: WorldPopulation::yearPopulation) {
        fout << to.second << ';';
    }

    fout.close();
}

