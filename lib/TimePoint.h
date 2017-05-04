#include <time.h>

#ifndef PERCENT_CLOCK_TIMEPOINT_H
#define PERCENT_CLOCK_TIMEPOINT_H

class TimePoint {
public:
    TimePoint(int hour);

    TimePoint(int hour, int min);

    time_t toTimeT();

private:
    time_t moment;
    struct tm *momentInfo;
};

#endif //PERCENT_CLOCK_TIMEPOINT_H
