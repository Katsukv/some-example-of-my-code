#include "src/part1/header_file/WorldPopulation.h"
#include "Program.h"
#include <iostream>

int main() {

    Program program;

    program.readCountryPopulationFromFile("D:/proga/bsu/lab7/data/world_population_1960-2018.csv", "D:/proga/bsu/lab7/data/countries.csv");
    program.writeWorldRegionPopulationToFile("D:/proga/bsu/lab7/data/output.csv");


    // WorldPopulation wp;
    // wp.readCountryPopulationFromFile("D:/proga/bsu/lab7/data/world_population_1960-2018.csv");
    // wp.calcWorldPopulation();
    // wp.writeCountryPopulationToFile("D:/proga/bsu/lab7/data/world_population_1960-2018.csv");

    return 0;
}
