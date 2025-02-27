//
// Created by User on 13.11.2024.
//

#ifndef STRUCTS_H
#define STRUCTS_H

#include <string>
#include <map>

struct Country {
    std::string contryName;
    std::string сountryCode;
    std::map<int,long long int> yearPopulation;

    std::string toString();
};

std::ostream& operator << (std::ostream& fout, const Country& countryFeature);

#endif //STRUCTS_H