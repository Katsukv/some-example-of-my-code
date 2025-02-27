//
// Created by User on 06.12.2024.
//
#include "CountryFeature.h"

std::ostream& operator << (std::ostream& fout, const CountryFeature& countryFeature) {
    fout << countryFeature.countryCode << ' ' << countryFeature.region << ' ';

    switch (countryFeature.IncomeGroup) {
        case IncomeGroup::HIGH: {
            fout << "HIGH";
            break;
        }
        case IncomeGroup::LOW: {
            fout << "LOW";
            break;
        }
        case IncomeGroup::LOWER_MIDDLE: {
            fout << "LOWER_MIDDLE";
            break;
        }
        case IncomeGroup::HIGH_MIDDLE: {
            fout << "HIGH_MIDDLE";
            break;
        }
    }

    return fout;
}