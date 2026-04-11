//
// Created by jan on 28/03/2026.
//

#include <stdio.h>
#include <time.h>
#include "../inc/Common.h"

#include <string.h>
#include <ctype.h>
#include "../inc/UI/Ansi.h"

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
    // get local time
    time_t tnow;
    time(&tnow);
    struct tm* now = localtime(&tnow);

    printf("CitizenDB\n");
    printf("(c) 2026, %s\n", AUTHOR);
    printf("\nLocal time is %s%02d:%02d:%02d%s.\n\n", ACCENT_TEXT, now->tm_hour, now->tm_min, now->tm_sec, RESET);
    return;
}

void CoPause(void) {
    printf("Press enter to continue... ");
    char num = 0;
    (void)scanf("%c", &num);
    return;
}

void CoClearBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
    return;
}

int CoReadString(char* buf, int n, FILE *stream) {
    printf("%s", ACCENT_TEXT);
    fgets(buf, n, stream);
    printf("%s", RESET);
    int len = strlen(buf);
    if (len > 0) {
        buf[len - 1] = '\0';
    }

    return len - 1;
}

int CoReadInt(int* buf)
{
    printf("%s", ACCENT_TEXT);
    int res = scanf("%d", buf);
    printf("%s", RESET);
    CoClearBuffer();
    return res;
}

int CoChoice(char *text) {
    if (text != NULL && text[0] != '\0') {
        printf("%s", text);
    } else {
        printf("Proceed?");
    }

    printf(" [Y/n]: ");

    char conf = 0;
    printf("%s", ACCENT_TEXT);
    (void)scanf(" %c", &conf);
    printf("%s", RESET);
    int res = (conf == 'Y' || conf == 'y') ? 1 : 0;
    CoClearBuffer();

    return res;
}

void CoSetConsoleTitle(char* text) {
    (void)printf("\033]0;%s\007", text);
    return;
}

void CoNormalize(char* buf)
{
    for (int i = 0; i < strlen(buf); i++)
    {
        buf[i] = tolower(buf[i]);
    }
}

unsigned long CoHash(unsigned char* str)
{
    unsigned long hash = 5381;
    int c;

    while (c = *str++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}