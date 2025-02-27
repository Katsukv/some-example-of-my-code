//
// Created by User on 06.12.2024.
//

#include "readCountryFromFile.h"
#include <fstream>

std::vector<Country> readCountryFromFile(const std::string& fileName) {
    std::vector<Country> countries;

    std::ifstream fin(fileName);
    std::string line;

    std::string startLine;

    std::getline(fin, startLine);

    while (std::getline(fin, line)) {
        line += ";";
        int i = 0;
        std::string s = "";

        Country tmp;

        for (auto to: line) {
            if (to == ';') {
                if (i == 0) {
                    tmp.contryName = s;
                } else if (i == 1) {
                    tmp.сountryCode = s;
                } else {

                    unsigned long x = 0;
                    for( auto to2 : s ) {
                        x = x * 10 + (unsigned long)(to2 - '0');
                    }
                    tmp.yearPopulation[1960+i-2] = x;
                }

                s = "";
                ++ i;
            }
            else {
                s += to;
            }
        }

        countries.push_back(tmp);
    }

    return countries;
}
