//
// Created by User on 06.12.2024.
//

#ifndef COUNTRYFEATURE_H
#define COUNTRYFEATURE_H

#include "IncomeGroup.h"
#include <string>
#include <fstream>

class CountryFeature {
public:
    std::string countryCode;
    std::string region;
    IncomeGroup IncomeGroup;
};

std::ostream& operator << (std::ostream& fout, const CountryFeature& countryFeature);

#endif //COUNTRYFEATURE_H
