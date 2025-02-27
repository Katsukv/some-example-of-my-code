//
// Created by User on 06.12.2024.
//

#include "readCountryFeatureFromFile.h"
#include <fstream>
#include <iostream>

std::vector<CountryFeature> readCountryFeatureFromFile(const std::string &file_name) {

    std::ifstream fin(file_name);

    if (!fin.is_open()) {
        std::cerr << "Error opening file " << file_name << std::endl;
    }

    std::vector< CountryFeature> result;

    std::string line;
    getline(fin, line);

    while (getline(fin, line)) {
        CountryFeature tmp;
        tmp.countryCode = line.substr(0, 3);
        line.erase(0, 4);

        tmp.region = line.substr(0, line.find(';'));
        line.erase(0, line.find(';') + 1);

        std:: string group = line.substr(0, line.find(';'));

        if (group == "High income") {
            tmp.IncomeGroup = IncomeGroup::HIGH;
        }
        else if(group == "Low income") {
            tmp.IncomeGroup = IncomeGroup::LOW;
        }
        else if (group == "Lower middle income") {
            tmp.IncomeGroup = IncomeGroup::LOWER_MIDDLE;
        }
        else {
            tmp.IncomeGroup = IncomeGroup::HIGH_MIDDLE;
        }

        result.push_back(tmp);
    }

    return result;
}
