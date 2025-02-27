cmake_minimum_required(VERSION 3.29)
project(lab7)

set(CMAKE_CXX_STANDARD 20)

include_directories(lib/spdlog/include)

include_directories(src/part1/header_file)
include_directories(src/part2/header_file)

add_executable(lab7 main.cpp
        ./src/part1/header_file/country.h
        ./src/part1/sours_file/country.cpp
        ./src/part1/header_file/WorldPopulation.h
        ./src/part1/sours_file/WorldPopulation.cpp
        src/part2/header_file/IncomeGroup.h
        src/part2/header_file/CountryFeature.h
        src/part2/header_file/readCountryFeatureFromFile.h
        src/part2/sours_file/readCountryFeatureFromFile.cpp
        src/part2/sours_file/CountryFeature.cpp
        src/part2/header_file/WorldCountry.h
        src/part2/header_file/Program.h
        src/part2/sours_file/Program.cpp
        src/part1/header_file/readCountryFromFile.h
        src/part1/sours_file/readCountryFromFile.cpp
        src/part2/header_file/WorldRegionPopulation.h
        src/part2/sours_file/WorldRegionPopulation.cpp
)
