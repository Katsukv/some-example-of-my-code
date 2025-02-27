//
// Created by User on 13.11.2024.
//
#include "country.h"
#include <string>
#include <map>

std::string Country::toString() {
    std::string ans = Country::contryName + "(" + Country::сountryCode + "):";

    for (auto to : Country::yearPopulation) {
        ans += " " + std::to_string(to.second) + "[";
        ans += std::to_string(to.first) + "],";
    }

    ans.erase(ans.size() - 1, 1);

    return ans;
}

std::ostream& operator << (std::ostream& fout, const Country& country) {
    fout << country.contryName << country.сountryCode;

    // for (auto to : country.yearPopulation) {
    //     fout << to.first << ' ' << to.second << '\n';
    // }

    return fout;
}