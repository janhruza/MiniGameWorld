//
// Created by jan on 21/03/2026.
//

#include "../inc/Common.h"

#include <stdio.h>

#include "../inc/UI/Ansi.h"

const char* CoGetStatus(const STATUS status) {
    switch (status) {
        case STATUS_OK:
            return "STATUS_OK";

        case STATUS_ERROR:
            return "STATUS_ERROR";

        case STATUS_UNINITIALIZED:
            return "STATUS_UNINITIALIZED";

        default:
        case STATUS_UNKNOWN:
            return "STATUS_UNKNOWN";
    }
}

STATUS CoDrawBanner(void) {
    printf("%s\n(c) 2026 %s%s%s\n\n", PRODUCT_NAME, ACCENT_TEXT, AUTHOR, RESET);
    return STATUS_OK;
}

const char* CoGetCountryName(Country country) {
    switch (country) {
        case COUNTRY_ARAGON: return "ESP";
        case COUNTRY_AUSTRALIA: return "AUS";
        case COUNTRY_AUSTRIA: return "AUT";
        case COUNTRY_BRAZIL: return "BRA";
        case COUNTRY_CATALONIA: return "ITA";
        case COUNTRY_CZECHIA: return "CZE";
        case COUNTRY_FRANCE: return "FRA";
        case COUNTRY_GERMANY: return "GER";
        case COUNTRY_GREAT_BRITAIN: return "GBR";
        case COUNTRY_HUNGARY: return "HUN";
        case COUNTRY_INDONESIA: return "IDN";
        case COUNTRY_ITALY: return "ITA";
        case COUNTRY_JAPAN: return "JPN";
        case COUNTRY_MALAYSIA: return "MYS";
        case COUNTRY_NETHERLANDS: return "NLD";
        case COUNTRY_PORTUGAL: return "PRT";
        case COUNTRY_QATAR: return "QAT";
        case COUNTRY_SAN_MARINO: return "SMR";
        case COUNTRY_SPAIN: return "ESP";
        case COUNTRY_SOUTH_AFRICA: return "ZAF";
        case COUNTRY_THAILAND: return "THA";
        case COUNTRY_TURKEY: return "TUR";
        case COUNTRY_USA: return "USA";
        case COUNTRY_VALENCIA: return "ITA";
        default: return "OTH";
    }
}