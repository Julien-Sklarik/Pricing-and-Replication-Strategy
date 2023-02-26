#include <cmath>

#include <limits>
#include <random>
#include <utility>
#include <iostream>

#include <vector>
#include <chrono>
using namespace std; 
#include <random>

#include "MCasianput.h"
#include "Option.h"



const std::string mcasianput::getName() const {
  return "Command giving the valuation of an asian put";
}





const std::string mcasianput::getDescription() const {
  return "This command gives the valutation of an asian put by using "
         "the Monte Carlo Method.";
}






vector<double> mcasianput:: LognormalDistributionSequence(const double& S, const double& r, const double& sigma,const double& time,const int& step)
{
    vector<double> prices(step);
    double dt = time/step;
    double R = (r - 0.5*pow(sigma,2))*dt; 
    
    double price = S; 
    unsigned seed =       
    std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator (seed);

    std::normal_distribution<double> distribution (0.0,1.0);
    for(int i=0; i<step; i++) 
    {      price = price*exp(R + sigma*sqrt(dt)*distribution(generator));
           prices[i] = price; }; 
    return prices; 
}







double mcasianput:: payoff_asian_put(const vector<double>& St,const double& strike){     double sum = accumulate(St.begin(), St.end(),0.0);
    double expectation = sum/St.size();
    return max(0.0,-expectation+strike); 
}









float mcasianput::asian_put_price(const double& S,const double& K, const double& r, const double& sigma,const double& time,const int& step,const int& no_sims)
{
  double s = 0;
  for (int n= 1; n<=no_sims; n++) 
    {
              vector<double>prices=LognormalDistributionSequence(S,r,sigma,time,step);
      s =  s + payoff_asian_put(prices,K); 
    }
  return exp(-r*time )*(s/double(no_sims));
}






bool mcasianput::operator()() {
  Parameters parameters{{"spot_price", ""},
                        {"interest_rate", ""},
                        {"volatility", ""},
                        {"strike_price", ""},
                        {"day_of_maturity", ""}, 
                        {"month_of_maturity", ""},
                        {"step", ""},
                        {"year_of_maturity", ""}};

  mcasianput::askParameters(parameters);
  Option option(parameters);


  int step = std::stof(parameters["step"]);
  float s = option.getSpotPrice();
  float r = option.getInterestRate();
  float sigma = option.getVolatility();
  float k = option.getStrikePrice();
  int n = option.getNumberOfSimulations();
  float t = option.periodDiff();

  std::cout << "The value of the option is " << asian_put_price(s,k,r,sigma,t,step,n) << std::endl;
  return true;
}