#include <vector>
#include <iostream>
#include <cmath>
using namespace std;
class Stats {
public:
    float average = NAN;
    float min = NAN;
    float max = NAN;
};
class IAlerter {
public:
    virtual void  alert() {}
    void dummy() { cout << "print" << endl; }
};
class EmailAlert : public IAlerter{
public:
    bool emailSent;
    EmailAlert() :emailSent(false) {}
    
    void alert() {
        emailSent = true;
    }
    void dummy() { cout << "print email" << endl; }
};
class LEDAlert : public IAlerter{
public:
    bool ledGlows;
    LEDAlert() :ledGlows(false) {}
    void alert() {
        ledGlows = true;
    }
};

class StatsAlerter {
public:
    const float maxThreshold;
    std::vector<IAlerter*> alerters;
    StatsAlerter(const float mt, std::vector<IAlerter*>  a) :maxThreshold(mt), alerters(a) {}
    void checkAndAlert(const std::vector<float>&);
};
namespace Statistics {
   
  
    Stats ComputeStatistics(const std::vector<float>& );
}
