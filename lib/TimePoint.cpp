#include "TimePoint.h"

TimePoint::TimePoint(int hour) {
    moment = time(nullptr);
    momentInfo = localtime(&moment);
    momentInfo->tm_hour = hour;
    momentInfo->tm_min = 0;
    momentInfo->tm_sec = 0;
    moment = mktime(momentInfo);
}

TimePoint::TimePoint(int hour, int min) {
    moment = time(nullptr);
    momentInfo = localtime(&moment);
    momentInfo->tm_hour = hour;
    momentInfo->tm_min = min;
    momentInfo->tm_sec = 0;
    moment = mktime(momentInfo);
}


time_t TimePoint::toTimeT() {
    return moment;
}
