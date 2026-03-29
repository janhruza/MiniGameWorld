//
// Created by jan on 28/03/2026.
//

#include <stdio.h>

#include "../inc/Common.h"

char gCountries[COUNTRIES_COUNT][COUNTRY_CODE_LEN] = {
    "USA", "CZE", "IRE", "GBR", "CAN", "AUS", "DEU", "FRA", "ITA", "ESP",
    "SVK", "POL", "AUT", "JPN", "CHN", "KOR", "IND", "BRA", "MEX", "ARG",
    "NLD", "BEL", "CHE", "SWE", "NOR", "DNK", "FIN", "PRT", "GRC", "TUR",
    "ISR", "SAU", "ARE", "EGY", "ZAF", "NGA", "KEN", "UKR", "ROU", "HUN",
    "HRV", "SVN", "BGR", "EST", "LVA", "LTU", "ISL", "IRL", "NZL", "SGP",
    "THA", "VNM", "MYS", "IDN", "PHL", "CHL", "COL", "PER", "VEN", "DOM",
    "CUB", "PAN", "CRI", "JAM", "MAR", "DZA", "TUN", "SEN", "GHA", "ETH",
    "TZA", "UGA", "LUX", "MLT", "CYP", "GEO", "ARM", "AZE", "KAZ", "UZB",
    "MNG", "PAK", "BGD", "LKA", "NPL", "MMR", "KHM", "LAO", "TWN", "HKG",
    "MAC", "QAT", "KWT", "OMN", "JOR", "LBN", "IRQ", "IRN", "AFG", "SRB"
};

void CoDrawBanner(void) {
    printf("CitizenDB\n");
    printf("(c) 2026, %s\n", AUTHOR);
    printf("\n");
    return;
}