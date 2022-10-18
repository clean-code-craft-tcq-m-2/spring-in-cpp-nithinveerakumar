#include "stats.h"

Stats Statistics::ComputeStatistics(const std::vector<float>& a) {
    Stats obj;
    float average = NAN;
    float min = NAN;
    float max = NAN;
    if (!a.empty())
    {
        min = a.at(0);
        max = a.at(0);
        average = 0;
    }

    for (auto x : a)
    {
        average += x;
        if (min > x)
            min = x;
        if (x > max)
            max = x;
     }
    if (!isnan(average))
    {
        obj.average = average / a.size();;
        obj.min = min;
        obj.max = max;
    }
    return obj;
}
void StatsAlerter::checkAndAlert(const std::vector<float>& a)
{
    auto computedStats = Statistics::ComputeStatistics(a);
    if (computedStats.max > maxThreshold)
    {
        alerters.emailSent = true;
        alerters.ledGlows = true;
    }
}
