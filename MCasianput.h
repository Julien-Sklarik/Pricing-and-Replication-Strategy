#ifndef COMMAND_ASIAN_PUT
#define COMMAND_ASIAN_PUT
#include "Option.h"
#include "Command.h"
#include <vector>
#include <algorithm>
using namespace std;

class mcasianput : public Command {
public:
  
const std::string getName() const override;;
const std::string getDescription() const override;;
vector<double>  LognormalDistributionSequence(const double& S, const double& r, const double& sigma,const double& time,const int& step);
double  payoff_asian_put(const vector<double>& St,const double& strike);
float asian_put_price(const double& S,const double& K, const double& r, const double& sigma,const double& time,const int& step,const int& no_sims);
 bool operator()() override;
};

#endif