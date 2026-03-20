//
// Created by jan on 20/03/2026.
//

#ifndef RALLYDAKAR_TIMESPAN_H
#define RALLYDAKAR_TIMESPAN_H

typedef struct {
    int Minutes;
    int Seconds;
} Timespan;

int TsFromSeconds(const float seconds, Timespan *timespan);

#endif //RALLYDAKAR_TIMESPAN_H