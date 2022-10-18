#include <vector>

class Stats {
public:
    float average = NAN;
    float min = NAN;
    float max = NAN;
};

class EmailAlert {
public:
    bool emailSent = false;
};
class LEDAlert {
public:
    bool ledGlows = false;
};
class IAlerter :public EmailAlert, public LEDAlert {

};
class StatsAlerter {
    float maxThreshold;
    IAlerter alerters;
    StatsAlerter(float mt, IAlerter a) :maxThreshold(mt), alerters(a) {}
    void checkAndAlert(const std::vector<float>&);
};
namespace Statistics {
   
  
    Stats ComputeStatistics(const std::vector<float>& );
}
