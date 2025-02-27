//
// Created by User on 06.12.2024.
//

#include "WorldRegionPopulation.h"

#include<iostream>
#include "spdlog/spdlog.h"

void WorldRegionPopulation::calcWorldRegionPopulation(std::vector<WorldCountry> worldCountry) {

    // spdlog::info("Uoy!");
    for (auto to : worldCountry) {
        // std::cout << to.countryFeature.countryCode << std::endl;
        for (auto to2 : to.yearPopulation) {
            // std::cout << to2.first << ' ' << to2.second << std::endl;
            WorldRegionPopulation::year_population[to2.first] += to2.second;
        }
    }
}